Info << "    Type: Forced Convection" << endl;
    simpleControl& simplec = simpleFluid[i];
Info << "ehsan0" << endl;
    // Solve the momentum equation

    tmp<fvVectorMatrix> UEqn
    (
        fvm::div(phi, U)
      + turb.divDevReff()
    );

    // Momentum solution
    eqnResidual = solve(relax(UEqn()) == -fvc::grad(p)).initialResidual();

    maxResidual = max(eqnResidual, maxResidual);
