#ifndef __VIEWER_POSE_HPP__
#define __VIEWER_POSE_HPP__
namespace viewer{
    class Pose{
    public:
        enum class JOINT_NAME{
            Top_head,
            Back_Head,
            Front_Head,
            L_Head_Offset,
            R_Shoulder,
            L_Shoulder,
            Neck,
            L_BackOffset,
            R_Bicep,
            R_Elbow,
            R_ForeArm,
            R_Radius,
            R_Ulna,
            R_Thumb,
            R_Pinky,
            L_Bicep,
            L_Elbow,
            L_Forearm,
            L_Radius,
            L_Ulna,
            L_Thumb,
            L_Pinky,
            R_ASIS,
            L_ASIS,
            R_PSIS,
            L_PSIS,
            V_Sacral,
            R_Thigh,
            R_Knee,
            R_Shank,
            R_Ankle,
            R_Heel,
            R_Toe,
            R_Foot,
            L_Thigh,
            L_Knee,
            L_Shank,
            L_Ankle,
            L_Toe,
            L_Heel,
            L_Foot
        };
        
        Pose();
    
    protected:
    
    private:
    
    };
}
#endif
