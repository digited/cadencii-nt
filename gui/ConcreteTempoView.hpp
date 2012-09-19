/**
 * ConcreteTempoView.h
 * Copyright © 2012 kbinani
 *
 * This file is part of cadencii.
 *
 * cadencii is free software; you can redistribute it and/or
 * modify it under the terms of the BSD License.
 *
 * cadencii is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 */
#ifndef __ConcreteTempoView_hpp__
#define __ConcreteTempoView_hpp__

#include "TempoView.hpp"
#include "gui/EditorWidgetBase.h"

namespace cadencii{

    class ConcreteTempoView : public EditorWidgetBase, public TempoView{
    private:
        ControllerAdapter *controllerAdapter;
        VSQ_NS::Sequence *sequence;
        QColor backgroundColor;
        QColor lineColor;

    public:
        ConcreteTempoView( QWidget *parent = 0 );

        ~ConcreteTempoView();

        void *getScrollEventSender();

        QSizeF getPreferedSceneSize();

        void *getWidget();

        void setControllerAdapter( ControllerAdapter *controllerAdapter );

        void setSequence( VSQ_NS::Sequence *sequence );

        void setDrawOffset( VSQ_NS::tick_t drawOffset );

        void paintMainContent( QPainter *painter, const QRect &rect );

        void paintSubContent( QPainter *painter, const QRect &rect );

        void drawMeasureLine( QPainter *painter, const QRect &rect, int x, const VSQ_NS::MeasureLine &measureLine );
    };

}

#endif
