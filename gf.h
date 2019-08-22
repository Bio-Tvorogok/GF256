#ifndef GF256_H
#define GF256_H

#include <QDebug>
#include <iostream>
#include <cstdlib>

static class GF
{
public:
    static uint32_t Plus(uint32_t one, uint32_t two) { return one ^ two; }
    static uint32_t Multiply(uint32_t one, uint32_t two) {
        uint32_t res = 0;
        while (two > 0){
            if ((two & 1) == 1)
                res = res ^ one;
            two = two >> 1;
            one = one << 1;
            if ((one & 0x100) > 0)
                one = one ^ 0x11B;
        }
        return res;
    }
    static uint32_t Square(uint32_t element){
        return Multiply(element, element);
    }

    static uint32_t MultiplicativeInverse(uint32_t element){
        uint32_t result = element;
        for (int i = 1; i < 31; i++)
            result = Multiply(Square(result), element);
        return Square(result);
    }

    static QString Out (uint32_t element){
        bool first = false;
        QString res;
        for (int i = 31; i >= 0; i--){
            if (((element >> i) & 1) && (i == 0)){
                if (first) {
                    res.append("+");
                } else first = true;
                res.append(" 1 ");
            }
            else if ((element >> i) & 1) {
                if (first) {
                    res.append("+");
                } else first = true;
                res.append(" x^");
                res.append(QString::number(i));
                res.append(" ");
            }
        }
        return res;
    }

};




#endif // GF256_H
