#include "House.h"

class Factory

{

public:

virtual House* Create() = 0;

virtual ~Factory(){}

};

class Cottage_Factory : public Factory

{

public:

House * Create(){ return new Cottage; }

};

class Panel_house_Factory : public Factory

{

public:

House * Create(){ return new Panel_house; }

};

class Brick_house_Factory : public Factory

{

public:

House * Create(){ return new Brick_house; }

};

class Brick_monolithic_house_Factory : public Factory

{

public:

House * Create(){ return new Brick_monolithic_house; }

};


House* CreateHouse(Factory *value)

{

return value->Create();

}