#include "MarioLauncherAttractor.h"

namespace NrvMarioLauncherAttractor {
    FULL_NERVE(MarioLauncherAttractorNrvWait, MarioLauncherAttractor, Wait);
};

MarioLauncherAttractor::MarioLauncherAttractor(const char* pName) : LiveActor(pName) {
    mGravityCreator = nullptr;
}

void MarioLauncherAttractor::init(const JMapInfoIter& rIter) {
    MR::initDefaultPos(this, rIter);
    initModelManagerWithAnm("MarioLauncherAttractor", nullptr, nullptr, false);

    mGravityCreator = new PointGravityCreator();
    mGravityCreator->createFromJMap(rIter);
    PlanetGravity* pGravity = mGravityCreator->getGravity();
    pGravity->mGravityType = GRAVITY_TYPE_MARIO_LAUNCHER;

    f32 clipping = pGravity->mRange / 1000.0f;
    MR::setClippingTypeSphere(this, pGravity->mRange);
    MR::setClippingFar200m(this);

    mScale.x = clipping;
    mScale.y = clipping;
    mScale.z = clipping;

    MR::connectToSceneMapObj(this);
    initNerve(&NrvMarioLauncherAttractor::MarioLauncherAttractorNrvWait::sInstance, 0);
    MR::startBtk(this, "MarioLauncherAttractor");

    makeActorAppeared();
}

void MarioLauncherAttractor::exeWait() {
}
