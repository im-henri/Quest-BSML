#pragma once

#include "BSML/Tags/BSMLTag.hpp"

#include "BSML/Data/RectTransformData.hpp"
#include "BSML/Data/ContentSizeFitterData.hpp"
#include "BSML/Data/BackgroundableData.hpp"

namespace BSML {
    class BackgroundTagParser;
    class BackgroundTag : private BSMLTag {
        public:
            BackgroundTag() : BSMLTag() {}
            virtual void Construct(UnityEngine::Transform* parent, Il2CppObject* host = nullptr) const override;
        protected:
            friend class BackgroundTagParser;
            virtual void parse(const tinyxml2::XMLElement& elem) override;

            virtual UnityEngine::GameObject* CreateObject(UnityEngine::Transform* parent) const override;

            BackgroundableData backgroundableData;
            ContentSizeFitterData contentSizeFitterData;
            RectTransformData rectTransformData;
    };
}
