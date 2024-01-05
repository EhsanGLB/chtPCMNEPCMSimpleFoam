//  Pressure-velocity SIMPLE corrector

    p.storePrevIter();


if(typeFluid[i] == "forcedConvection")
{
    #include "forcedConvection/UEqnFC.H"
    #include "forcedConvection/TEqnFC.H"
    #include "forcedConvection/pEqnFC.H"
}


if(typeFluid[i] == "naturalConvection")
{
    #include "naturalConvection/UEqnNC.H"
    #include "naturalConvection/TEqnNC.H"
    #include "naturalConvection/pEqnNC.H"
}


if(typeFluid[i] == "PCM")
{
    #include "PCM/UEqnPCM.H"
    #include "PCM/TEqnPCM.H"
    #include "PCM/pEqnPCM.H"
}


turb.correct();

