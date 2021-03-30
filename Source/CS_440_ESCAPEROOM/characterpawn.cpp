// Fill out your copyright notice in the Description page of Project Settings.


#include "characterpawn.h"

// Sets default values
Acharacterpawn::Acharacterpawn()
{
	ImpulseForceJump = 500.0f;
	ImpulseForceMove = 100.0f;
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	//VisibleComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("VisibleComponent"));
	//SetUp RootComponent
	
	RotatorComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RotatorComponent"));
	ConnectionComponent = CreateDefaultSubobject<USceneComponent>(TEXT("ConnectionComponent"));

	//SetUp VisisbleComponent and attach to RootComponent
	VisibleComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("VisibleComponent"));
	OurCameraSpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("OurCameraSpringArm"));
	OurCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("OurCamera"));
	RootComponent = VisibleComponent;
	//VisibleComponent->SetupAttachment(RootComponent);
	VisibleComponent->SetSimulatePhysics(true);
	VisibleComponent->SetGenerateOverlapEvents(true);

	VisibleComponent->SetupAttachment(RootComponent);

	ConnectionComponent->SetupAttachment(VisibleComponent);
	ConnectionComponent->SetUsingAbsoluteRotation(false);
	RotatorComponent->SetupAttachment(ConnectionComponent);
	//RotatorComponent->SetUsingAbsoluteRotation(true);
	OurCameraSpringArm->SetupAttachment(RotatorComponent);

	OurCamera->SetupAttachment(OurCameraSpringArm);
}


// Called when the game starts or when spawned
void Acharacterpawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void Acharacterpawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void Acharacterpawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	// Check if PlayerInputComponent is valid (not NULL)
	check(PlayerInputComponent);
	InputComponent = PlayerInputComponent;
	//UE_LOG(LogTemp, Warning, TEXT("Postregisterallcomponents CALLED"));

	//PlayerInputComponent->BindAction("Pause", IE_Pressed, this, &ASnake::Pause);
	//PlayerInputComponent->BindAxis("Boost", this, &ASnake::MoveFowardBoost);
	PlayerInputComponent->BindAxis("UPorDOWN_Camera", this, &Acharacterpawn::movecameraupordown);
	PlayerInputComponent->BindAxis("SIDE2SIDE_Camera", this, &Acharacterpawn::movecamerside2side);
	PlayerInputComponent->BindAxis("Forward", this, &Acharacterpawn::MoveForward);
	PlayerInputComponent->BindAxis("Right", this, &Acharacterpawn::MoveRight);

	PlayerInputComponent->BindAction("Jumpup", IE_Pressed, this, &Acharacterpawn::jumpup);

}

void Acharacterpawn::movecameraupordown(float input)
{
	FRotator CameraRotation = RotatorComponent->GetRelativeRotation();
	CameraRotation.Yaw += input;
	RotatorComponent->SetRelativeRotation(CameraRotation);
	//UE_LOG(LogTemp, Warning, TEXT("Camera rotation Y = %d "),CameraRotation.Yaw);
}

void Acharacterpawn::movecamerside2side(float input)
{
	FRotator CameraRotation = RotatorComponent->GetRelativeRotation();
	CameraRotation.Pitch += input;
	RotatorComponent->SetRelativeRotation(CameraRotation);
	//UE_LOG(LogTemp, Warning, TEXT("Camera rotation Z = %d "), CameraRotation.Pitch);
}

void Acharacterpawn::MoveForward(float input)
{
		FVector CameraForward = OurCamera->GetForwardVector();
		VisibleComponent->AddImpulse(CameraForward*ImpulseForceMove*VisibleComponent->GetMass()*input);
}
void Acharacterpawn::MoveRight(float input)
{
	FVector CameraRight = OurCamera->GetRightVector();
	VisibleComponent->AddImpulse(CameraRight*ImpulseForceMove*VisibleComponent->GetMass()*input);
}
void Acharacterpawn::jumpup()
{
	    
		if (abs(GetVelocity().Z)< 10)
		{
			/*
			FVector Loc;
			FRotator Rot;
			FHitResult Hit;

			GetController()->GetPlayerViewPoint(Loc, Rot);
			float TraceDistance = 300;
			FVector Start = Loc;
			FVector End = Start + (Rot.Vector()*TraceDistance);

			FCollisionQueryParams TraceParams;

			bool bHit = GetWorld()->LineTraceSingleByChannel(Hit, Start, End, ECC_Visibility, TraceParams);

			if (bHit)
			{
				UStaticMeshComponent* MeshComp = Cast<UStaticMeshComponent>(Hit.GetActor()->GetRootComponent());
				if (MeshComp)
				{
					FVector CameraForward = OurCamera->GetForwardVector();
					MeshComp->AddImpulse(CameraForward*ImpulseForce* MeshComp->GetMass());
				}
			}
			*/
			FVector UP = { 0,0,1 };

			VisibleComponent->AddImpulse(UP*ImpulseForceJump*VisibleComponent->GetMass());
		}

	//UE_LOG(LogTemp, Warning, TEXT("JumpUp"));
}


