#pragma once
#include "syati.h"  

class PointGravityCreator;

class MarioLauncherAttractor : public LiveActor {
public:
    MarioLauncherAttractor(const char* pName);

    virtual ~MarioLauncherAttractor() {
    }
    virtual void init(const JMapInfoIter& rIter);

    void exeWait();

    PointGravityCreator* mGravityCreator;  // 0x8C
};
