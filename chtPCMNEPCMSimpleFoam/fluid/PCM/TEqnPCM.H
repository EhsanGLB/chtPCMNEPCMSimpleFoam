
{
    volScalarField kappaEff("kappaEff", (turb.nut()/Prt) * rho * Cp + kappa);
    kappaEff.correctBoundaryConditions();

    Kappa = kappaEff;

    volScalarField gammaT ("gammaT", hm*4.0*exp(-pow(4.0*(T-Tm)/Tmr,2))/Foam::sqrt(mathematicalConstant::pi)/Tmr); //added

    fvScalarMatrix TEqn
    (
        rho*Cp*fvm::div(phi, T)
      - fvm::laplacian(kappaEff, T)
      + rho*Cp*fvm::SuSp(-fvc::div(phi), T)
      + rho*gammaT*fvm::ddt(T)
      + rho*gammaT*(U & fvc::grad(T))
    );

    TEqn.relax();

    eqnResidual = TEqn.solve().initialResidual();
    maxResidual = max(eqnResidual, maxResidual);

    rhok = 1.0 - beta*(T - TRef);
    gamma = 0.5 * erf( 4.0 * ( T - Tm ) / Tmr ) + scalar(0.5);

    #include "setRegionFluidFields.H"
}
