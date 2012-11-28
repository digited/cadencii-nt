/**
 * XVSQFileReader.hpp
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
#ifndef CADENCII_SEQUENCE_IO_XVSQFILEREADER_HPP_
#define CADENCII_SEQUENCE_IO_XVSQFILEREADER_HPP_

#include <string>
#include <stack>
#include "../../vsq/Sequence.hpp"
#include "SAXAdapter.hpp"

namespace cadencii {

    /**
     * @brief A parser class for XVSQ file.
     */
    class XVSQFileReader {
        friend class SAXAdapter;

    private:
        VSQ_NS::Sequence *sequence;
        VSQ_NS::Track currentTrack;
        int trackCount;
        std::stack<std::string> tagNameStack;

        std::map<std::string, VSQ_NS::DynamicsMode::DynamicsModeEnum> dynamicsModeValueMap;
        std::map<std::string, VSQ_NS::PlayMode::PlayModeEnum> playModeValueMap;

    protected:
        SAXAdapter *adapter;

    public:
        XVSQFileReader();

        /**
         * @brief Read XVSQ from specified SAX(Simple API for XML) adapter.
         */
        void read(VSQ_NS::Sequence *sequence, SAXAdapter *adapter);

    protected:
        void startElement(const std::string &name);

        void endElement(const std::string &name);

        void characters(const std::string &ch);

    private:
        template<class T>
        inline void insertEnumValueMap(std::map<std::string, T> &result, const T &enumValue);
    };
}

#endif
