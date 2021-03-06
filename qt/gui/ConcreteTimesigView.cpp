/**
 * ConcreteTimesigView.cpp
 * Copyright © 2012 kbinani
 *
 * This file is part of cadencii.
 *
 * cadencii is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * version 2.0 as published by the Free Software Foundation.
 *
 * cadencii is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 */
#include <string>
#include "ConcreteTimesigView.hpp"
#include "ui_EditorWidgetBase.h"

namespace cadencii {

    ConcreteTimesigView::ConcreteTimesigView(QWidget *parent) :
        EditorWidgetBase(parent) {
        backgroundColor = QColor(Qt::lightGray);
        lineColor = QColor::fromRgb(104, 104, 104);
        const int height = 19;
        setMinimumHeight(height);
        setMaximumHeight(height);
        ui->mainContent->setBackgroundBrush(QBrush(backgroundColor));
    }

    ConcreteTimesigView::~ConcreteTimesigView() {
    }

    void ConcreteTimesigView::setControllerAdapter(ControllerAdapter *controllerAdapter) {
        this->controllerAdapter = controllerAdapter;
    }

    void ConcreteTimesigView::setDrawOffset(VSQ_NS::tick_t drawOffset) {
        setDrawOffsetInternal(drawOffset);
    }

    void *ConcreteTimesigView::getWidget() {
        return this;
    }

    void *ConcreteTimesigView::getScrollEventSender() {
        return static_cast<TimesigView *>(this);
    }

    void ConcreteTimesigView::paintMainContent(QPainter *painter, const QRect &rect) {
        // 小節ごとの線
        ui->mainContent->paintMeasureLines(painter, rect);

        // 直下のコンポーネントとの区切り線
        painter->setPen(lineColor);
        painter->drawLine(rect.bottomLeft(), rect.bottomRight());

        // 拍子変更
        const VSQ_NS::Sequence *sequence = controllerAdapter->getSequence();
        if (sequence) {
            const VSQ_NS::TimesigList *list = &sequence->timesigList;
            const int DRAW_WIDTH = 100;
            int count = list->size();
            for (int i = 0; i < count; i++) {
                const VSQ_NS::Timesig timesig = list->get(i);
                int x = controllerAdapter->getXFromTick(timesig.getClock());
                if (x + DRAW_WIDTH < rect.left()) {
                    continue;
                }
                std::string  text
                        = StringUtil::toString(timesig.numerator) + "/"
                        + StringUtil::toString(timesig.denominator);
                QString qText(text.c_str());
                static QTextOption option(Qt::AlignLeft | Qt::AlignVCenter);
                const int drawWidth = 200;
                QRectF textRect(x + 5, rect.top(), drawWidth, rect.height());
                painter->setPen(Qt::black);
                painter->drawText(textRect, qText, option);
            }
        }

        // ソングポジション
        ui->mainContent->paintSongPosition(painter, rect);
    }

    void ConcreteTimesigView::drawMeasureLine(
            QPainter *painter, const QRect &rect, int x,
            const VSQ_NS::MeasureLine &measureLine) {
        painter->setPen(lineColor);
        if (measureLine.isBorder) {
            painter->drawLine(x, rect.top(), x, rect.bottom());
        } else {
            int lineHeight = measureLine.isAssistLine ? 3 : 6;
            painter->drawLine(x, rect.bottom() - lineHeight, x, rect.bottom());
        }
    }

    void ConcreteTimesigView::paintSubContent(QPainter *painter, const QRect &rect) {
        painter->fillRect(rect, backgroundColor);
        painter->setPen(lineColor);
        painter->drawLine(rect.bottomLeft(), rect.bottomRight());
        painter->drawLine(rect.topRight(), rect.bottomRight());

        painter->setPen(Qt::black);
        static QString text("BEAT");
        static QTextOption option(Qt::AlignLeft | Qt::AlignVCenter);
        QRectF textRect(rect.left() + 10, rect.top(), rect.width() - 10, rect.height());
        painter->drawText(textRect, text, option);
    }

    void ConcreteTimesigView::updateWidget() {
        repaint();
    }
}
