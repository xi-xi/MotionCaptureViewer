#ifndef __VIEWER_POSE_HPP__
#define __VIEWER_POSE_HPP__
namespace viewer{
    class Pose{
    public:
        enum class JOINT_NAME{
            TopHead,
            BackHead,
            FrontHead,
            LHeadOffset,
            RShoulder,
            LShoulder,
            Neck,
            LBackOffset,
            RBicep,
            RElbow,
            RForeArm,
            RRadius,
            RUlna,
            RThumb,
            RPinky,
            LBicep,
            LElbow,
            LForearm,
            LRadius,
            LUlna,
            LThumb,
            LPinky,
            RASIS,
            LASIS,
            RPSIS,
            LPSIS,
            VSacral,
            RThigh,
            RKnee,
            RShank,
            RAnkle,
            RHeel,
            RToe,
            RFoot,
            LThigh,
            LKnee,
            LShank,
            LAnkle,
            LToe,
            LHeel,
            LFoot
        };
        
        Pose();
    
    protected:
    
    private:
    
    };
}
#endif
