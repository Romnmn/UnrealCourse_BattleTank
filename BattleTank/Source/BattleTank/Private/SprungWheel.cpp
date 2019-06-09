// Daragan inc.


#include "SprungWheel.h"

// Sets default values
ASprungWheel::ASprungWheel()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	MassWheelConstraint = CreateDefaultSubobject<UPhysicsConstraintComponent>(FName("PhysicsConstraint"));
	RootComponent = MassWheelConstraint;

	//Mass = CreateDefaultSubobject<UStaticMeshComponent>(FName("Mass"));
	//Mass->AttachToComponent(MassWheelConstraint, FAttachmentTransformRules::KeepRelativeTransform);
	//Mass->SetNotifyRigidBodyCollision(true);
	//Mass->SetSimulatePhysics(true);

	Wheel = CreateDefaultSubobject<UStaticMeshComponent>(FName("Wheel"));
	Wheel->AttachToComponent(MassWheelConstraint, FAttachmentTransformRules::KeepRelativeTransform);
	Wheel->SetNotifyRigidBodyCollision(true);
	Wheel->SetSimulatePhysics(true);

	//Settup

	//MassWheelConstraint->SetConstrainedComponents(Mass, "", Wheel, "");

	MassWheelConstraint->SetLinearXLimit(ELinearConstraintMotion::LCM_Locked, 0);
	MassWheelConstraint->SetLinearYLimit(ELinearConstraintMotion::LCM_Locked, 0);
	MassWheelConstraint->SetLinearZLimit(ELinearConstraintMotion::LCM_Free, 0);

	MassWheelConstraint->SetAngularSwing1Limit(EAngularConstraintMotion::ACM_Locked, 0);
	MassWheelConstraint->SetAngularSwing2Limit(EAngularConstraintMotion::ACM_Locked, 0);
	MassWheelConstraint->SetAngularTwistLimit(EAngularConstraintMotion::ACM_Locked, 0);

	//end settup
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
		MassWheelConstraint->SetConstrainedComponents(BodyRoot, NAME_None, Wheel, NAME_None);
	}
}

// Called every frame
void ASprungWheel::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

