// Fill out your copyright notice in the Description page of Project Settings.


#include "FlashingLight.h"
#include "Components/PointLightComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
AFlashingLight::AFlashingLight()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	RootComponent = root;

	mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	mesh->AttachTo(root);

	pointLight = CreateDefaultSubobject<UPointLightComponent>(TEXT("Light"));
	pointLight->AttachTo(root);

	collisionCapsule = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Capsule"));
	collisionCapsule->InitCapsuleSize(180.f, 180.f);
	collisionCapsule->SetupAttachment(RootComponent);
	collisionCapsule->OnComponentBeginOverlap.AddDynamic(this, &AFlashingLight::BeginOverlap);
	collisionCapsule->OnComponentEndOverlap.AddDynamic(this, &AFlashingLight::EndOverlap);
	
	timeCounter = 0;

	morseCode.Init(false, 20);
	
	
}

// Called when the game starts or when spawned
void AFlashingLight::BeginPlay()
{
	Super::BeginPlay();
	
	FVector location = GetActorLocation();

	if (location.X == -1220) {
		delay = 1.f;
		morseCode.Insert(true, 1);
		morseCode.Insert(true, 3);
		morseCode.Insert(true, 5);
		morseCode.Insert(true, 6);
		morseCode.Insert(true, 7);
		morseCode.Insert(true, 9);
		morseCode.Insert(true, 10);
		morseCode.Insert(true, 13);
		morseCode.Insert(true, 15);
		morseCode.Insert(true, 17);
		morseCode.Insert(true, 20);
	}
	else if (location.X == -1770) {
		delay = .5;
		morseCode.Insert(true, 1);
		morseCode.Insert(true, 3);
		morseCode.Insert(true, 5);
		morseCode.Insert(true, 7);
		morseCode.Insert(true, 9);
		morseCode.Insert(true, 11);
		morseCode.Insert(true, 13);
		morseCode.Insert(true, 15);
		morseCode.Insert(true, 17);
		morseCode.Insert(true, 20);
	}
	else if (location.X == -2480.f){
		delay = 0.25;
		morseCode.Insert(true, 3);
		morseCode.Insert(true, 5);
		morseCode.Insert(true, 6);
		morseCode.Insert(true, 7);
		morseCode.Insert(true, 10);
		morseCode.Insert(true, 13);
		morseCode.Insert(true, 14);
		morseCode.Insert(true, 17);
		morseCode.Insert(true, 20);
	}
}

// Called every frame
void AFlashingLight::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AFlashingLight::BeginOverlap(UPrimitiveComponent* OverlappedComponent,
	AActor* OtherActor,
	UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex,
	bool bFromSweep,
	const FHitResult& SweepResult)
{

	if (OtherActor && (OtherActor != this) && OtherComp) {
		//UE_LOG(LogTemp, Warning, TEXT("In Begin Overlap"));
		GetWorldTimerManager().SetTimer(timeManageHandler, this, &AFlashingLight::Flicker, delay, true, 2.f);
	}
}


void AFlashingLight::EndOverlap(UPrimitiveComponent* OverlappedComponent,
	AActor* OtherActor,
	UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex)
{
	
	GetWorldTimerManager().ClearTimer(timeManageHandler);
	timeCounter = 0;
}

void AFlashingLight::Flicker()
{
	if (timeCounter > 20)
	{
		timeCounter = 0;
		GetWorldTimerManager().ClearTimer(timeManageHandler);
		//UE_LOG(LogTemp, Warning, TEXT("Clearing time"));
	}

	//UE_LOG(LogTemp, Warning, TEXT("In Flicker"));

	if (morseCode[timeCounter]) {
		pointLight->SetIntensity(lightOn);
	}
	else {
		pointLight->SetIntensity(lightOff);
	}

	timeCounter += 1;
}

