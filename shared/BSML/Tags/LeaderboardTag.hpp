#pragma once

#include "BSML/Tags/BSMLTag.hpp"

namespace BSML {
    class LeaderboardTag : public BSMLTag {
        public:
            LeaderboardTag() : BSMLTag() {}
        protected:
            virtual UnityEngine::GameObject* CreateObject(UnityEngine::Transform* parent) const override;
    };
}