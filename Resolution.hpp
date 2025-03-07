#ifndef RESOLUTION_H
#define RESOLUTION_H

class Resolution{

    public:
        Resolution();
        Resolution(int x, int y);
        Resolution(Resolution &resolution);
        
        void setResolution(int x, int y);

        int getX();
        int getY();
    private:
        int x,y;
};


#endif