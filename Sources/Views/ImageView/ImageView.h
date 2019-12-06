//
// Created by Сергей Петренко on 2019-11-16.
//

#ifndef CPPROJECT_IMAGEVIEW_H
#define CPPROJECT_IMAGEVIEW_H


#include "Container/ContainerView.h"

class ImageView: public ContainerView{


private:
    std::string src;
    int height;
    int width;

public:
    void append(ContainerView &mView);
    bool appendInSubview(std::string subviewName, ContainerView& mView);
    void removeSubview(std::string subviewName);
    void destroy();
    ImageView() = default;
    ImageView(std::string n, Type t, BClass c, std::string s, int h, int w);
    std::string toStringOpen(int depth = 0) override;
    std::string toStringClose(int depth = 0) override;
    std::string toString(int depth = 0) override;
};


#endif //CPPROJECT_IMAGEVIEW_H
