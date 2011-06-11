//
//  HelloWorldScene.h
//  BubbleBlitz
//
//  Created by Robert Backman on 12/31/10.
//  Copyright Student: UC Merced 2010. All rights reserved.
//


// When you import this file, you import all the cocos2d classes
#import "cocos2d.h"
#import "Box2D.h"
#import "GLES-Render.h"
#import "GameConfig.h"
//Pixel to metres ratio. Box2D uses metres as the unit for measurement.
//This ratio defines how many pixels correspond to 1 Box2D "metre"
//Box2D is optimized for objects of 1x1 metre therefore it makes sense
//to define the ratio so that your most common object type is 1x1 metre.
#define PTM_RATIO 32

@class MatchObject;
@class WavePool;
@class SoundLayer;
// HelloWorld Layer
@interface GameScene : CCLayer
{
    SoundLayer* sound;
    
	int difficulty;
	bool first;
	CCSprite* background;
	b2World* world;
	GLESDebugDraw *m_debugDraw;
	CGSize screenSize;
	int maxMatchObjects;
	WavePool* waves;
	bool addition;
	bool subtraction;
	bool multiplication;
	bool remainder;
	bool division;
    float levelUpScale;
    bool levelUp;
    CCLabelTTF* levelUpLabel; 
}

// returns a Scene that contains the HelloWorld as the only child
+(id) scene;

// adds a new sprite at a given coordinate
-(void)addMatchObject;
-(void) addMatchObjectAtPosition:(CGPoint)p value:(int)v;
-(void)addRippleAt:(CGPoint)position radius:(int)r value:(int)v;
-(void)newGame;
-(CCArray*)MatchObjects;
-(int)numMatchObjects;
-(MatchObject*)getMatchObject:(int)i;
-(int)getMatchObjectValue:(int)i;


@property (nonatomic,readonly) b2World* world;
@property (nonatomic,readwrite)int difficulty;
@property (nonatomic,readwrite)bool addition;
@property (nonatomic,readwrite)bool subtraction;
@property (nonatomic,readwrite)bool multiplication;
@property (nonatomic,readwrite)bool remainder;
@property (nonatomic,readwrite)bool division;
@end