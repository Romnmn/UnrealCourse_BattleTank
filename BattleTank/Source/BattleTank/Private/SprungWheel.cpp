// Daragan inc.


#include "SprungWheel.h"

// Sets default values
ASprungWheel::ASprungWheel()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	AxisToMassConstraint = CreateDefaultSubobject<UPhysicsConstraintComponent>(FName("AxisPhysicsConstraint"));
	RootComponent = AxisToMassConstraint;

	Axis = CreateDefaultSubobject<USphereComponent>(FName("Axis"));
	Axis->AttachToComponent(AxisToMassConstraint, FAttachmentTransformRules::KeepRelativeTransform);
	Axis->SetNotifyRigidBodyCollision(false);
	Axis->SetSimulatePhysics(true);

	WheelToAxisConstraint = CreateDefaultSubobject<UPhysicsConstraintComponent>(FName("WheelPhysicsConstraint"));
	WheelToAxisConstraint->AttachToComponent(Axis, FAttachmentTransformRules::KeepRelativeTransform);

	Wheel = CreateDefaultSubobject<USphereComponent>(FName("Wheel"));
	Wheel->AttachToComponent(WheelToAxisConstraint, FAttachmentTransformRules::KeepRelativeTransform);
	Wheel->SetNotifyRigidBodyCollision(true);
	Wheel->SetSimulatePhysics(true);

	//axis
	AxisToMassConstraint->SetLinearXLimit(ELinearConstraintMotion::LCM_Locked, 0);
	AxisToMassConstraint->SetLinearYLimit(ELinearConstraintMotion::LCM_Locked, 0);
	AxisToMassConstraint->SetLinearZLimit(ELinearConstraintMotion::LCM_Free, 0);

	AxisToMassConstraint->SetAngularSwing1Limit(EAngularConstraintMotion::ACM_Locked, 0);
	AxisToMassConstraint->SetAngularSwing2Limit(EAngularConstraintMotion::ACM_Locked, 0);
	AxisToMassConstraint->SetAngularTwistLimit(EAngularConstraintMotion::ACM_Locked, 0);

	//wheel
	WheelToAxisConstraint->SetLinearXLimit(ELinearConstraintMotion::LCM_Locked, 0);
	WheelToAxisConstraint->SetLinearYLimit(ELinearConstraintMotion::LCM_Locked, 0);
	WheelToAxisConstraint->SetLinearZLimit(ELinearConstraintMotion::LCM_Locked, 0);

	WheelToAxisConstraint->SetAngularSwing1Limit(EAngularConstraintMotion::ACM_Locked, 0);
	WheelToAxisConstraint->SetAngularSwing2Limit(EAngularConstraintMotion::ACM_Free, 0);
	WheelToAxisConstraint->SetAngularTwistLimit(EAngularConstraintMotion::ACM_Locked, 0);
}

void ASprungWheel::AddDrivingForce(float ForceMagnitude)
{
	Wheel->AddForce(Axis->GetForwardVector() * ForceMagnitude);
}

// Called when the game starts or when spawned
void ASprungWheel::BeginPlay()
{
	Super::BeginPlay();

	SetConstraint();
}

void ASprungWheel::SetConstraint()
{
	if (GetAttachParentActor())
	{
		UE_LOG(LogTemp, Warning, TEXT("Parrent %s"), *GetAttachParentActor()->GetName());

		UPrimitiveComponent* BodyRoot = Cast<UPrimitiveComponent>(GetAttachParentActor()->GetRootComponent());
		if (!BodyRoot) { return; }
		AxisToMassConstraint->SetConstrainedComponents(BodyRoot, NAME_None, Axis, NAME_None);
		WheelToAxisConstraint->SetConstrainedComponents(Axis, NAME_None, Wheel, NAME_None);
	}
}

// Called every frame
void ASprungWheel::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

