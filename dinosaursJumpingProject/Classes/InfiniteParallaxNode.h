#include "cocos2d.h"
USING_NS_CC;

class InfiniteParallaxNode: public ParallaxNode{
private:

public:
    static InfiniteParallaxNode* create();
    void updatePosition();
};

