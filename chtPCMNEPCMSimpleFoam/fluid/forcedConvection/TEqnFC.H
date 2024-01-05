
{
    volScalarField kappaEff("kappaEff", (turb.nut()/Prt) * rho * Cp + kappa);
    kappaEff.correctBoundaryConditions();

    Kappa = kappaEff;

    fvScalarMatrix TEqn
    (
        rho*Cp*fvm::div(phi, T)
      - fvm::laplacian(kappaEff, T)
    );

    TEqn.relax();

    eqnResidual = TEqn.solve().initialResidual();
    maxResidual = max(eqnResidual, maxResidual);

    #include "setRegionFluidFields.H"
}
