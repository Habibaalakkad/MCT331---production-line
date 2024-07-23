% Simscape(TM) Multibody(TM) version: 7.3

% This is a model data file derived from a Simscape Multibody Import XML file using the smimport function.
% The data in this file sets the block parameter values in an imported Simscape Multibody model.
% For more information on this file, see the smimport function help page in the Simscape Multibody documentation.
% You can modify numerical values, but avoid any other changes to this file.
% Do not add code to this file. Do not edit the physical units shown in comments.

%%%VariableName:smiData


%============= RigidTransform =============%

%Initialize the RigidTransform structure array by filling in null values.
smiData.RigidTransform(10).translation = [0.0 0.0 0.0];
smiData.RigidTransform(10).angle = 0.0;
smiData.RigidTransform(10).axis = [0.0 0.0 0.0];
smiData.RigidTransform(10).ID = '';

%Translation Method - Cartesian
%Rotation Method - Arbitrary Axis
smiData.RigidTransform(1).translation = [149.87878787749599 227.51515147767299 -180.16300000000001];  % mm
smiData.RigidTransform(1).angle = 9.0262402714153088e-16;  % rad
smiData.RigidTransform(1).axis = [0.1844992474011122 -0.98283265498681072 -8.183725821898727e-17];
smiData.RigidTransform(1).ID = 'B[cartisolated:1:-:gripperrrisolated:1]';

%Translation Method - Cartesian
%Rotation Method - Arbitrary Axis
smiData.RigidTransform(2).translation = [11.575757699115623 -0.21212120896062348 -116.01630846623918];  % mm
smiData.RigidTransform(2).angle = 1.2267826126004912e-16;  % rad
smiData.RigidTransform(2).axis = [0.048606206244929513 0.99881801981866314 2.9779384047789188e-18];
smiData.RigidTransform(2).ID = 'F[cartisolated:1:-:gripperrrisolated:1]';

%Translation Method - Cartesian
%Rotation Method - Arbitrary Axis
smiData.RigidTransform(3).translation = [221.61591816057199 357.18569588462799 310.707502897734];  % mm
smiData.RigidTransform(3).angle = 2.0943951023931953;  % rad
smiData.RigidTransform(3).axis = [-0.57735026918962618 -0.57735026918962562 0.5773502691896254];
smiData.RigidTransform(3).ID = 'B[CARTESIAAAN:1:-:cartisolated:1]';

%Translation Method - Cartesian
%Rotation Method - Arbitrary Axis
smiData.RigidTransform(4).translation = [424.09436538993594 331.5526624991985 -26.730385809063542];  % mm
smiData.RigidTransform(4).angle = 2.0943951023931962;  % rad
smiData.RigidTransform(4).axis = [-0.5773502691896254 -0.57735026918962584 0.57735026918962595];
smiData.RigidTransform(4).ID = 'F[CARTESIAAAN:1:-:cartisolated:1]';

%Translation Method - Cartesian
%Rotation Method - Arbitrary Axis
smiData.RigidTransform(5).translation = [-320.04053183992312 493.12322306590715 10];  % mm
smiData.RigidTransform(5).angle = 2.0943951023931957;  % rad
smiData.RigidTransform(5).axis = [0.57735026918962584 -0.57735026918962573 0.57735026918962573];
smiData.RigidTransform(5).ID = 'B[tableiso:1:-:CARTESIAAAN:1]';

%Translation Method - Cartesian
%Rotation Method - Arbitrary Axis
smiData.RigidTransform(6).translation = [-310.82841052963204 470.85754553583456 30];  % mm
smiData.RigidTransform(6).angle = 2.0943951023931957;  % rad
smiData.RigidTransform(6).axis = [0.57735026918962584 -0.57735026918962573 0.57735026918962573];
smiData.RigidTransform(6).ID = 'F[tableiso:1:-:CARTESIAAAN:1]';

%Translation Method - Cartesian
%Rotation Method - Arbitrary Axis
smiData.RigidTransform(7).translation = [-55.790000791462759 -2.6984496035199612 -50.696009397506657];  % mm
smiData.RigidTransform(7).angle = 2.0943951023931953;  % rad
smiData.RigidTransform(7).axis = [0.57735026918962584 -0.57735026918962584 0.57735026918962584];
smiData.RigidTransform(7).ID = 'B[feedingpressisolated:1:-:tableiso:1]';

%Translation Method - Cartesian
%Rotation Method - Arbitrary Axis
smiData.RigidTransform(8).translation = [247.78034079365185 -351.72641004922292 43.057643325943346];  % mm
smiData.RigidTransform(8).angle = 2.094395102393197;  % rad
smiData.RigidTransform(8).axis = [-0.57735026918962673 -0.57735026918962629 0.57735026918962418];
smiData.RigidTransform(8).ID = 'F[feedingpressisolated:1:-:tableiso:1]';

%Translation Method - Cartesian
%Rotation Method - Arbitrary Axis
smiData.RigidTransform(9).translation = [10.121212229069748 2.7878787463361432 -129.09384077883607];  % mm
smiData.RigidTransform(9).angle = 0;  % rad
smiData.RigidTransform(9).axis = [0 0 0];
smiData.RigidTransform(9).ID = 'RootGround[tableiso:1]';

%Translation Method - Cartesian
%Rotation Method - Arbitrary Axis
smiData.RigidTransform(10).translation = [73.26371049965131 -325.62527988980008 379.59534780209799];  % mm
smiData.RigidTransform(10).angle = 7.6853241871389388e-16;  % rad
smiData.RigidTransform(10).axis = [0.34949295489584581 0.84854869255566567 0.39726539094192531];
smiData.RigidTransform(10).ID = 'SixDofRigidTransform[cuboid:1]';


%============= Solid =============%
%Center of Mass (CoM) %Moments of Inertia (MoI) %Product of Inertia (PoI)

%Initialize the Solid structure array by filling in null values.
smiData.Solid(6).mass = 0.0;
smiData.Solid(6).CoM = [0.0 0.0 0.0];
smiData.Solid(6).MoI = [0.0 0.0 0.0];
smiData.Solid(6).PoI = [0.0 0.0 0.0];
smiData.Solid(6).color = [0.0 0.0 0.0];
smiData.Solid(6).opacity = 0.0;
smiData.Solid(6).ID = '';

%Inertia Type - Custom
%Visual Properties - Simple
smiData.Solid(1).mass = 9.9590760561657543;  % kg
smiData.Solid(1).CoM = [-9.7981949320949422 -64.523329598634348 -6.6622626613008027];  % mm
smiData.Solid(1).MoI = [851970.95660610381 430663.91229796381 1257952.9161198428];  % kg*mm^2
smiData.Solid(1).PoI = [27763.226379226428 -5742.9758286455854 44455.175131777716];  % kg*mm^2
smiData.Solid(1).color = [0.74901960784313726 0.74901960784313726 0.74901960784313726];
smiData.Solid(1).opacity = 1;
smiData.Solid(1).ID = 'tableiso.ipt_{27E4F878-4914-F1F4-60D0-7E9FE2F503BF}';

%Inertia Type - Custom
%Visual Properties - Simple
smiData.Solid(2).mass = 2.2412351265277826;  % kg
smiData.Solid(2).CoM = [149.87713060499317 271.57323358413925 -2.1408585781224918];  % mm
smiData.Solid(2).MoI = [34646.139114120582 32927.518630648032 8331.5020481133834];  % kg*mm^2
smiData.Solid(2).PoI = [3173.599739650077 1.0087082581831055 -0.16276172845391557];  % kg*mm^2
smiData.Solid(2).color = [0.74901960784313726 0.74901960784313726 0.74901960784313726];
smiData.Solid(2).opacity = 1;
smiData.Solid(2).ID = 'cartisolated.ipt_{2EF9BFC3-407A-D440-33E4-368DD916C7A0}';

%Inertia Type - Custom
%Visual Properties - Simple
smiData.Solid(3).mass = 0.38400000000000001;  % kg
smiData.Solid(3).CoM = [20 -20 15];  % mm
smiData.Solid(3).MoI = [80 80 102.40000000000001];  % kg*mm^2
smiData.Solid(3).PoI = [0 0 0];  % kg*mm^2
smiData.Solid(3).color = [0.74901960784313726 0.74901960784313726 0.74901960784313726];
smiData.Solid(3).opacity = 1;
smiData.Solid(3).ID = 'cuboid.ipt_{2CF62B95-41BE-21EC-2A38-3987372B67B0}';

%Inertia Type - Custom
%Visual Properties - Simple
smiData.Solid(4).mass = 0.052312864250451882;  % kg
smiData.Solid(4).CoM = [-55.790000791525536 -80.111020927368472 -50.696062515745773];  % mm
smiData.Solid(4).MoI = [88.817311897219582 4.4241896073379392 88.800367023835676];  % kg*mm^2
smiData.Solid(4).PoI = [-0.00010167007458221632 0 -4.8417300149594668e-06];  % kg*mm^2
smiData.Solid(4).color = [0.74901960784313726 0.74901960784313726 0.74901960784313726];
smiData.Solid(4).opacity = 1;
smiData.Solid(4).ID = 'feedingpressisolated.ipt_{499E4CE8-4E2E-581E-3F25-0980184274A1}';

%Inertia Type - Custom
%Visual Properties - Simple
smiData.Solid(5).mass = 0.57318033662361767;  % kg
smiData.Solid(5).CoM = [11.551694550009184 -12.164721335329062 -4.1287552243950847];  % mm
smiData.Solid(5).MoI = [965.34712107570112 1171.6247673269381 1689.3363881654445];  % kg*mm^2
smiData.Solid(5).PoI = [-196.71588448934261 -0.075910547920682345 -0.8319668154393981];  % kg*mm^2
smiData.Solid(5).color = [0.74901960784313726 0.74901960784313726 0.74901960784313726];
smiData.Solid(5).opacity = 1;
smiData.Solid(5).ID = 'gripperrrisolated.ipt_{6EFBDA0D-4C52-8D87-7883-6A9D07F15BE0}';

%Inertia Type - Custom
%Visual Properties - Simple
smiData.Solid(6).mass = 1.8691727204758704;  % kg
smiData.Solid(6).CoM = [-79.635242824995913 399.22248545398139 230.09437166406838];  % mm
smiData.Solid(6).MoI = [27902.659983674293 144049.47431756274 117701.02494600294];  % kg*mm^2
smiData.Solid(6).PoI = [893.81288482409434 2836.4564749177139 -214.36858958045488];  % kg*mm^2
smiData.Solid(6).color = [0.74901960784313726 0.74901960784313726 0.74901960784313726];
smiData.Solid(6).opacity = 1;
smiData.Solid(6).ID = 'CARTESIAAAN.ipt_{29F7D5C3-4A11-A69A-FD39-F18C6B9EA997}';


%============= Joint =============%
%X Revolute Primitive (Rx) %Y Revolute Primitive (Ry) %Z Revolute Primitive (Rz)
%X Prismatic Primitive (Px) %Y Prismatic Primitive (Py) %Z Prismatic Primitive (Pz) %Spherical Primitive (S)
%Constant Velocity Primitive (CV) %Lead Screw Primitive (LS)
%Position Target (Pos)

%Initialize the CylindricalJoint structure array by filling in null values.
smiData.CylindricalJoint(3).Rz.Pos = 0.0;
smiData.CylindricalJoint(3).Pz.Pos = 0.0;
smiData.CylindricalJoint(3).ID = '';

smiData.CylindricalJoint(1).Rz.Pos = 0.076818398272388885;  % deg
smiData.CylindricalJoint(1).Pz.Pos = 0;  % mm
smiData.CylindricalJoint(1).ID = '[cartisolated:1:-:gripperrrisolated:1]';

smiData.CylindricalJoint(2).Rz.Pos = -0.30392278186053406;  % deg
smiData.CylindricalJoint(2).Pz.Pos = 0;  % mm
smiData.CylindricalJoint(2).ID = '[CARTESIAAAN:1:-:cartisolated:1]';

smiData.CylindricalJoint(3).Rz.Pos = -90.000000000001322;  % deg
smiData.CylindricalJoint(3).Pz.Pos = 0;  % mm
smiData.CylindricalJoint(3).ID = '[feedingpressisolated:1:-:tableiso:1]';


%Initialize the PrismaticJoint structure array by filling in null values.
smiData.PrismaticJoint(1).Pz.Pos = 0.0;
smiData.PrismaticJoint(1).ID = '';

smiData.PrismaticJoint(1).Pz.Pos = 0;  % m
smiData.PrismaticJoint(1).ID = '[tableiso:1:-:CARTESIAAAN:1]';

