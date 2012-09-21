/**
 * TimesigView.hpp
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
#ifndef __TimesigView_hpp__
#define __TimesigView_hpp__

#include "ControllerAdapter.hpp"
#include "vsq/Sequence.hpp"

namespace cadencii{

    class TimesigView{
    public:
        /**
         * @brief ControllerAdapter のインスタンスを設定する
         */
        virtual void setControllerAdapter( ControllerAdapter *controllerAdapter ) = 0;

        /**
         * @brief 描画対象のシーケンスを設定する
         * @param items 描画対象のシーケンス
         */
        virtual void setSequence( VSQ_NS::Sequence *sequence ) = 0;

        /**
         * @brief 描画範囲の左端の、tick 単位の時刻を設定する
         * @param drawOffset 描画範囲の左端の時刻
         */
        virtual void setDrawOffset( VSQ_NS::tick_t drawOffset ) = 0;

        /**
         * @brief ウィジェットの実体を返す
         * @return ウィジェットの実体
         */
        virtual void *getWidget() = 0;
    };

}

#endif