#ifndef RESOLUTION_H
#define RESOLUTION_H

class Resolution{

    public:
        Resolution();
        Resolution(int x, int y);
        Resolution(Resolution &r);


    private:
        int x,y;
};


#endif