//
//  Bubble.h
//  BubbleBlitz
//
//  Created by Robert Backman on 12/31/10.
//  Copyright 2010 Student: UC Merced. All rights reserved.
//

#import "cocos2d.h"
#import "Box2D.h"
#import "IntegerNode.h"

//the MatchObject (not the best name I know) is represents one value to match it handles the touches and contains a group of bubbles
@interface MatchObject : CCNode <CCTargetedTouchDelegate, NSCoding>
{
	    
	CCSprite* glowSprite;    //this sprite shows which bubbles are selected so they don't have to be popped at the same time.. probably not the best
    float glowScale;         //this is essentialy a timer to determine if the object has been selected recently
    NSMutableArray* bubbles; //the group of bubbles that belong to this object
	IntegerNode* intNode;    //class for generating expresions
	int value;				//Inherent value of the MatchObject types
	CCLabelTTF* label;       //can be used to display the text for the expression or value
    CGPoint centroid;        //this is the point at the center of the object.. just the average of each bubbles position
    
    bool alive;              //flag to have this object deleted
	bool isTouchEnabled_;    //the touching happens at the MatchObject level but maybe it should be on each bubble
	CGPoint touchStart;
	
}

-(bool)isActive;      //this object has been recently selected
-(void)activate;    //make the glow sprite visible and activate
-(void)destroy;     //remove all bubbles and call removeFromParent

+(id)matchObjectWithPosition:(CGPoint)p value:(int)v;  //autorelease version of constructor
-(id)initWithPosition:(CGPoint)p value:(int)v;
-(void) update: (ccTime) dt;                      



-(void)addForce:(CGPoint)f;     //add a linear force to each bubble in the group
-(int)val;                      //the value of he group
-(CGPoint)position;          //this is the position of the centroid

-(void) setIsTouchEnabled:(BOOL)enabled priority:(int)pr; //activate touches for this object

@property(nonatomic,readwrite)bool alive;
@end