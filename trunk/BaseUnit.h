#ifndef BASEUNIT__H__
#define BASEUNIT__H__

#include <iostream>
#include <string>
#include <list>
#include "BaseObject.h"
#include "BaseGraphicObject.h"
#include "Sprite.h"
#include "SDLCursor.h"

using namespace std;

class BaseUnit:public BaseObject, public BaseGraphicObject
{
	public: 
	BaseUnit();
	BaseUnit(SDL_Surface *scr, Player *p, string n);
	virtual ~BaseUnit();
	
	enum direction { N=0, NE=1, E=2, SE=3, S=4, SW=5, W=6, NW=7 };
	void setState(string state);
	void setYon(direction d);
	bool isWaiting();
	
	virtual void issueCommand(int x, int y) { cerr << "base unit issueCommand is called, err??" << endl; }
	virtual void defaultAction(int tx, int ty) { cerr << "base unit default action is called, err?" << endl; }
	virtual void update() { doUpdate(); }
	
	
	virtual SDL_Surface* getImg()
	{
		sprites[yon].setState(curState);
		return sprites[yon].getImg();
	}
	
	virtual SDL_Rect getFrame()
	{
		sprites[yon].setState(curState);
		SDL_Rect r = sprites[yon].getFrame();
		return r;
	}
	
	virtual void cancelActions()
	{
		cancelBaseActions();
	}
	
	void moveToTarget(int tx, int ty);
	void calWalkTile(int tx, int ty);
	void actionDur();
	void setCommandYuru();
	void cancelBaseActions();
	list<Coordinates> target;
	list<Coordinates> targetTiles;
	list<string>commandList;
	int getSight();
	bool onScreen(int x1, int x2, int y1, int y2);
	void draw(SDL_Rect s, SDL_Rect d); 
	
	void doUpdate();
	
	SDLProgressBar *sbar;
	SDLLabel *birimAdi, 
		*stArmor, *stArmorVal, 
		*stDamage, *stDamageVal, 
		*stRange, *stRangeVal, 
		*stSight, *stSightVal, 
		*stSpeed, *stSpeedVal, 
		*stMorale, *stMoraleVal,
		*stXp, *stXpVal, 
		*stKills, *stKillsVal;
	
	protected:
	int armor;
	int damage;
	int range;
	int sight;
	int speed;
	int morale;
	int xp;
	int kills;
	int tax, tay; // target x, target y
	int cux, cuy;
	
	int lastUpdate;
	bool areWeThereYet;
	
	// grafikler için
	string waitingCommand;
	bool waiting;
	direction yon;
	string curState;
	Sprite sprites[8];
};



#endif
