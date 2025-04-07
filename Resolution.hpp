#ifndef RESOLUTION_H
#define RESOLUTION_H

class Resolution{

    public:
        Resolution();
        Resolution(int x, int y);
        Resolution(Resolution &resolution);

        // Getters
        int getX();
        int getY();

        // Setter
        void setResolution(int x, int y);

    private:
        int x,y;
};


#endif