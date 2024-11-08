#include "Bloks.h"
#include "Positions.h"
class LBlock : public Bloks
{
public:
    LBlock()
    {
        id = 1;
        Cells[0] = {Positions(0, 2), Positions(1, 0), Positions(1, 1), Positions(1, 2)};
        Cells[1] = {Positions(0, 1), Positions(1, 1), Positions(2, 1), Positions(2, 2)};
        Cells[2] = {Positions(1, 0), Positions(1, 1), Positions(1, 2), Positions(2, 0)};
        Cells[3] = {Positions(0, 0), Positions(0, 1), Positions(1, 1), Positions(2, 1)};
        Move(0 , 3); 
    }
};

class IBlock : public Bloks {
public:
    IBlock() {
        id = 2;
        Cells[0] =  {Positions(2, 0), Positions(2, 1), Positions(2, 2), Positions(2, 3)};;
        Cells[1] = {Positions(0, 1), Positions(1, 1), Positions(2, 1), Positions(3, 1)};
        Cells[2] = {Positions(0, 2), Positions(1, 2), Positions(2, 2), Positions(3, 2)};
        Cells[3] = {Positions(1, 0), Positions(1, 1), Positions(1, 2), Positions(1, 3)};
        Move(-1 , 3); 
    }
};


class OBlock : public Bloks {
public:
    OBlock() {
        id = 3;
        Cells[0] = {Positions(0, 0), Positions(0, 1), Positions(1, 0), Positions(1, 1)};
        Cells[1] = Cells[0];
        Cells[2] = Cells[0];
        Cells[3] = Cells[0];
        Move(0 , 4); 
    }
};


class TBlock : public Bloks {
public:
    TBlock() {
        id = 4;
        Cells[0] = {Positions(0, 1), Positions(1, 0), Positions(1, 1), Positions(1, 2)};
        Cells[1] = {Positions(0, 1), Positions(1, 1), Positions(1, 2), Positions(2, 1)};
        Cells[2] = {Positions(1, 0), Positions(1, 1), Positions(1, 2), Positions(2, 1)};
        Cells[3] = {Positions(0, 1), Positions(1, 0), Positions(1, 1), Positions(2, 1)};
        Move(0 , 3);
    }
};


class SBlock : public Bloks {
public:
    SBlock() {
        id = 5;
        Cells[0] = {Positions(0, 1), Positions(0, 2), Positions(1, 0), Positions(1, 1)};
        Cells[1] = {Positions(0, 1), Positions(1, 1), Positions(1, 2), Positions(2, 2)};
        Cells[2] = {Positions(1, 1), Positions(1, 2), Positions(2, 0), Positions(2, 1)};
        Cells[3] = {Positions(0, 0), Positions(1, 0), Positions(1, 1), Positions(2, 1)};
        Move(0 , 3);
    }
};


class ZBlock : public Bloks {
public:
    ZBlock() {
        id = 6;
        Cells[0] = {Positions(0, 0), Positions(0, 1), Positions(1, 1), Positions(1, 2)};
        Cells[1] = {Positions(0, 2), Positions(1, 1), Positions(1, 2), Positions(2, 1)};
        Cells[2] = {Positions(1, 0), Positions(1, 1), Positions(2, 1), Positions(2, 2)};
        Cells[3] = {Positions(0, 1), Positions(1, 0), Positions(1, 1), Positions(2, 0)};
        Move(0 , 3);
    }
};




class JBlock : public Bloks {
public:
    JBlock() {
        id = 7;
        Cells[0] = {Positions(0, 0), Positions(1, 0), Positions(1, 1), Positions(1, 2)};
        Cells[1] = {Positions(0, 1), Positions(0, 2), Positions(1, 1), Positions(2, 1)};
        Cells[2] = {Positions(1, 0), Positions(1, 1), Positions(1, 2), Positions(2, 2)};
        Cells[3] = {Positions(0, 1), Positions(1, 1), Positions(2, 0), Positions(2, 1)};
        Move(0 , 3);
    }
};