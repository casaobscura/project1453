CC=g++
FLAGS=`sdl-config --cflags` -c 
LIBS=`sdl-config --libs` -lSDL_image -lSDL_gfx -lSDL_ttf

all: g1453

again: clean all

g1453: main.o \
	Application.o \
	Game.o \
	Player.o \
	SDLWidget.o \
	SDLButton.o \
	SDLFont.o \
	SDLCombo.o \
	SDLLabel.o \
	SDLCheckBox.o \
	SDLTextView.o \
	SDLListView.o \
	SDLProgressBar.o \
	SDLCommandButton.o \
	SDLScreen.o \
	ScreenMain.o \
	ScreenGameType.o \
	Resource.o \
	Resources.o \
	Cost.o \
	BaseObject.o \
	BaseGraphicObject.o \
	BaseUnit.o \
	Units.o \
	BaseBuilding.o \
	Buildings.o \
	Tech.o \
	Technologies.o \
	Sprite.o 
	
	$(CC) $(LIBS) main.o \
	Application.o \
	Game.o \
	Player.o \
	SDLWidget.o \
	SDLButton.o \
	SDLFont.o \
	SDLCombo.o \
	SDLLabel.o \
	SDLCheckBox.o \
	SDLTextView.o \
	SDLListView.o \
	SDLProgressBar.o \
	SDLCommandButton.o \
	SDLScreen.o \
	ScreenMain.o \
	ScreenGameType.o \
	Resource.o \
	Resources.o \
	Cost.o \
	BaseObject.o \
	BaseGraphicObject.o \
	BaseUnit.o \
	Units.o \
	BaseBuilding.o \
	Buildings.o \
	Tech.o \
	Technologies.o \
	Sprite.o -o g1453
	
main.o: main.cpp
	$(CC) $(FLAGS) main.cpp
	
Application.o: Application.cpp
	$(CC) $(FLAGS) Application.cpp

ScreenMain.o: ScreenMain.cpp
	$(CC) $(FLAGS) ScreenMain.cpp

ScreenGameType.o: ScreenGameType.cpp
	$(CC) $(FLAGS) ScreenGameType.cpp

# game related

Player.o: Player.cpp
	$(CC) $(FLAGS) Player.cpp

Game.o: Game.cpp
	$(CC) $(FLAGS) Game.cpp

BaseObject.o: BaseObject.cpp
	$(CC) $(FLAGS) BaseObject.cpp

BaseGraphicObject.o: BaseGraphicObject.cpp
	$(CC) $(FLAGS) BaseGraphicObject.cpp

BaseUnit.o: BaseUnit.cpp
	$(CC) $(FLAGS) BaseUnit.cpp

Units.o: Units.cpp
	$(CC) $(FLAGS) Units.cpp

BaseBuilding.o: BaseBuilding.cpp
	$(CC) $(FLAGS) BaseBuilding.cpp

Buildings.o: Buildings.cpp
	$(CC) $(FLAGS) Buildings.cpp

Resource.o: Resource.cpp
	$(CC) $(FLAGS) Resource.cpp
	
Resources.o: Resources.cpp
	$(CC) $(FLAGS) Resources.cpp

Cost.o: Cost.cpp
	$(CC) $(FLAGS) Cost.cpp

Tech.o: Tech.cpp
	$(CC) $(FLAGS) Tech.cpp
	
Technologies.o: Technologies.cpp
	$(CC) $(FLAGS) Technologies.cpp


# Additional 

Sprite.o: Sprite.cpp
	$(CC) $(FLAGS) Sprite.cpp

SDLCommandButton.o: SDLCommandButton.cpp
	$(CC) $(FLAGS) SDLCommandButton.cpp

# SDLGUI base below

SDLScreen.o: SDLScreen.cpp
	$(CC) $(FLAGS) SDLScreen.cpp

SDLWidget.o: SDLWidget.cpp
	$(CC) $(FLAGS) SDLWidget.cpp
	
SDLButton.o: SDLButton.cpp
	$(CC) $(FLAGS) SDLButton.cpp

SDLFont.o: SDLFont.cpp
	$(CC) $(FLAGS) SDLFont.cpp

SDLCombo.o: SDLCombo.cpp
	$(CC) $(FLAGS) SDLCombo.cpp

SDLLabel.o: SDLLabel.cpp
	$(CC) $(FLAGS) SDLLabel.cpp
	
SDLCheckBox.o: SDLCheckBox.cpp
	$(CC) $(FLAGS) SDLCheckBox.cpp
	
SDLTextView.o: SDLTextView.cpp
	$(CC) $(FLAGS) SDLTextView.cpp

SDLListView.o: SDLListView.cpp
	$(CC) $(FLAGS) SDLListView.cpp

SDLProgressBar.o: SDLProgressBar.cpp
	$(CC) $(FLAGS) SDLProgressBar.cpp

clean:
	rm -rf *.o g1453

