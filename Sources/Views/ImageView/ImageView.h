//
// Created by Сергей Петренко on 2019-11-16.
//

#ifndef CPPROJECT_IMAGEVIEW_H
#define CPPROJECT_IMAGEVIEW_H


#include <Container/ContainerView.h>

class ImageView : public ContainerView {
private:
    std::string src;
    int height;
    int width;

    void destroy() override;

public:
    bool append(ContainerView &mView) override;

    bool
    appendInSubview(std::string subviewName, ContainerView &mView) override;

    bool removeSubview(std::string subviewName) override;

    ImageView() = default;

    ~ImageView();

    ImageView(std::string containerName, Type containerType, BClass containerClass, std::string containerSource, int heigt, int width);
    ImageView(std::string containerName, Type containerType, BClass containerClass, std::string containerSource);

    std::string toStringOpen(int depth) override;

    std::string toStringClose(int depth) override;

    std::string toString(int depth) override;
};


#endif //CPPROJECT_IMAGEVIEW_H
