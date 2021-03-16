// Fill out your copyright notice in the Description page of Project Settings.



#include "slidingdoorplusvolume.h"
#include "characterpawn.h"

// Sets default values
Aslidingdoorplusvolume::Aslidingdoorplusvolume()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	opendoorb = 0;
	CustomUserValue = 70;
	CustomUserchar = "Y";
	CollisionBox = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComponent"));
	CollisionBox->SetGenerateOverlapEvents(true);
	CollisionBox->SetupAttachment(RootComponent);
	VisibleComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("VisibleComponent"));
	VisibleComponent->AttachToComponent(CollisionBox, FAttachmentTransformRules::KeepRelativeTransform);
	CollisionBox->OnComponentBeginOverlap.AddDynamic(this, &Aslidingdoorplusvolume::OnComponentBeginOverlap);
}

// Called when the game starts or when spawned
void Aslidingdoorplusvolume::BeginPlay()
{
	Super::BeginPlay();
	//UE_LOG(LogTemp, Warning, TEXT("Overlap CALLED"));
	//UE_LOG(LogTemp, Warning, TEXT("Overlap CALLED"));
}

void Aslidingdoorplusvolume::OnComponentBeginOverlap(UPrimitiveComponent * OverlappedComp,
	AActor * OtherActor,
	UPrimitiveComponent * OtherComp,
	int32 OtherBodyIndex,
	bool bFromSweep,
	const FHitResult & SweepResult)
{
	auto lv = VisibleComponent->GetComponentLocation();
	//UE_LOG(LogTemp, Warning, TEXT("Overlap CALLED actor loaction X %d Y %d z %d"), lv.X, lv.Y, lv.Z);
	//if ((Cast<Acharacterpawn>(OtherActor)))
	//{
	//	UE_LOG(LogTemp, Warning, TEXT("Overlap CALLED"));
	//}
	opendoor();
}

void Aslidingdoorplusvolume::opendoor()
{
	opendoorb = 1;
}
// Called every frame
void Aslidingdoorplusvolume::Tick(float DeltaTime)
{

	Super::Tick(DeltaTime);
	if (opendoorb)
	{
		int Direction = -1;
		auto lv = this->GetActorLocation();
		if (CustomUserchar == "Y" || CustomUserchar == "y")
		{
			if ((lv.Y - CustomUserValue) < 0)
			{
				Direction = 1;
			}
			else if ((lv.Y - CustomUserValue) > 0)
			{
				Direction = -1;
			}			
			else
			{
				Direction = 0;
			}
			if (!(lv.Y <= CustomUserValue))
			{
				lv.Y += (Direction*4.f);
				this->SetActorLocation(lv);
			}
			else
			{
				opendoorb = false;
			}
		}
		else if (CustomUserchar == "Z" || CustomUserchar == "z")
		{
			if ((lv.Y - CustomUserValue) < 0)
			{
				Direction = 1;
			}
			else if ((lv.Y - CustomUserValue) > 0)
			{
				Direction = -1;
			}
			else
			{
				Direction = 0;
			}
			if (!(lv.Z <= CustomUserValue))
			{
				lv.Z += (Direction*4.f);
				this->SetActorLocation(lv);
			}
			else
			{
				opendoorb = false;
			}
		}
		else
		{
			if ((lv.Y - CustomUserValue) < 0)
			{
				Direction = 1;
			}
			else if ((lv.Y - CustomUserValue) > 0)
			{
				Direction = -1;
			}
			else
			{
				Direction = 0;
			}
			if (!(lv.X <= CustomUserValue))
			{
				lv.X += (Direction*4.f);
				this->SetActorLocation(lv);
			}
			else
			{
				opendoorb = false;
			}
		}
	}
}

