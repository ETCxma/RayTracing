#ifndef PIXEL_H
#define PIXEL_H

class Pixel{
    
    public:
        Pixel();
        Pixel(int intensite);
        Pixel(Pixel &&pixel);
        Pixel(Pixel &pixel);

        int getIntensite();
        void setIntensite(int value);
        void addIntensite(int value);
        
    private:
        int intensite; // Can be replaced by r,g,b or anything else

};

#endif 