#ifndef PIXEL_H
#define PIXEL_H

class Pixel{
    
    public:
        Pixel();
        Pixel(int intensite);
        Pixel(Pixel &pixel);

        int getIntensite();
        
    private:
        int intensite; // Can be replaced by r,g,b or anything else

};

#endif 