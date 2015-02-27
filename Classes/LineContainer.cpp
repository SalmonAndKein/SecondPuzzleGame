//
//  LineContainer.cpp
//  SecondPuzzleGame
//
//  Created by Myloi Mellanc on 2015. 2. 27..
//
//

#include "LineContainer.h"
USING_NS_CC;


void LineContainer::draw(Renderer *renderer, const Mat4 &transform, uint32_t flags)
{
    switch (line_type)
    {
        case LINE_NONE:
            break;
            
        case LINE_DRAW:
            cmd.init(_globalZOrder);
            cmd.func = CC_CALLBACK_0(LineContainer::onDraw,this,transform,flags);
            renderer->addCommand(&cmd);
            break;
    }
    
}


void LineContainer::onDraw(const Mat4 &transform, uint32_t flags)
{
    
    
    DrawPrimitives::setDrawColor4B(255, 0, 0, 255);
    glLineWidth(4.0f);
    DrawPrimitives::drawLine(tap,pivot);
    CHECK_GL_ERROR_DEBUG();
    
}