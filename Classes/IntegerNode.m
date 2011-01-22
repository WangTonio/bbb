#import "IntegerNode.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>

static bool seedInit = NO;

//function for randomly selecting one factor of the integer x
static int getFactor(int x)
{
	NSMutableArray *factors = [[NSMutableArray alloc] init];
	int i = 0,count = 0;
	for (i = 1; i <= sqrt(x); i++)
	{
		if (x % i == 0)
		{
			[factors addObject:[NSNumber numberWithInt:i]];
			count++;
		}
	}
	if (count == 0) return 1;
	NSNumber* n = [factors objectAtIndex:(rand() % count)];
	return [n integerValue];
}

@implementation IntegerOperator
- (id) initNode:(IntegerNode*) node
{
	self = [super init];
	if(self){
		if(!seedInit){
			srand ( time(NULL) );
			seedInit=YES;
		}
		int v = [node getVal];
		int x = 0;
		int o = rand() % 5;
		switch(o)
		{
			case 0:
				opString = @"+";
				x = rand() % v;
				leftOperand = [[IntegerNode alloc] initNode:node startVal:x];
				rightOperand = [[IntegerNode alloc] initNode:node startVal:(v-x)];	
				break;
			case 1:
				opString = @"-";
				x = v + rand() % v;
				leftOperand = [[IntegerNode alloc] initNode:node startVal:x];
				rightOperand = [[IntegerNode alloc] initNode:node startVal:(x-v)];					
				break;
			case 2:
				opString = @"x";
				x = getFactor(v);
				leftOperand = [[IntegerNode alloc] initNode:node startVal:x];
				rightOperand = [[IntegerNode alloc] initNode:node startVal:(v/x)];	
				break;
			case 3:
				opString = @"/";
				x = getFactor(v);
				leftOperand = [[IntegerNode alloc] initNode:node startVal:x*v];
				rightOperand = [[IntegerNode alloc] initNode:node startVal:x];		
				break;
			case 4:
				opString = @"%";
				x = rand() % 10;
				x = (v > x)?(v+1):x;
				int y = v/x;
				leftOperand = [[IntegerNode alloc] initNode:node startVal:y*x+v];
				rightOperand = [[IntegerNode alloc] initNode:node startVal:x];		
				break;
		}
		
		

	}
	return self;
}

- (NSString *) getResultString
{
	//pretty sure this leaks memory
	return [NSString stringWithFormat:@"(%@ %@ %@)",[leftOperand getTreeString],opString,[rightOperand getTreeString]];
	
}

@end

@implementation IntegerNode
- (id) initNode:(IntegerNode*) node  startVal:(int) value;
{
	self = [super init];
	if(self){
		self->val = value;
		op = NULL;
	}
	return self;
}
- (void) expand
{
	op = [[IntegerOperator alloc] initNode:self];
}

- (NSString*) getTreeString
{
	if(op != NULL) return [NSString stringWithFormat:@"%d = %@", val, [op getResultString]];
	return [NSString stringWithFormat:@"%d", val];
	
}
- (NSString*) getNodeString
{
	return [NSString stringWithFormat:@"%d", val];
}
- (bool) checkEqual:(IntegerNode*) node
{
	return (node->val == val);
}

- (int) getVal
{
	return val;
}
@end