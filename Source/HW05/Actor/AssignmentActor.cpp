// AssignmentActor.cpp

#include "AssignmentActor.h"
#include "Engine/Engine.h"
#include "Math/UnrealMathUtility.h"

AAssignmentActor::AAssignmentActor()
{
    PrimaryActorTick.bCanEverTick = true;

    SetActorLocation(FVector(0.f, 50.f, 0.f));
}

void AAssignmentActor::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

void AAssignmentActor::PrintLocation()
{
    FVector A = GetActorLocation();
    if (GEngine)
    {
        GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::White,
            FString::Printf(TEXT("현재 좌표값: X=%.1f Y=%.1f Z=%.1f"), A.X, A.Y, A.Z));
    }
}

void AAssignmentActor::BeginPlay()
{
    Super::BeginPlay();

    PrintLocation(); 

    RandomMoveTurn();
}

void AAssignmentActor::Move(float Distance)
{
    FVector Move = GetActorLocation();
    float Angle = FMath::RandRange(0.f, 360.f);
    Move.X += FMath::Cos(FMath::DegreesToRadians(Angle)) * Distance;
    Move.Y += FMath::Cos(FMath::DegreesToRadians(Angle)) * Distance;

    SetActorLocation(Move);

    PrintLocation();
}

void AAssignmentActor::Turn(float Degrees, float DeltaZ)
{
    FRotator Turn = GetActorRotation();
    Turn.Yaw += Degrees;
    SetActorRotation(Turn);

    FVector Z = GetActorLocation();
    Z.Z += DeltaZ;
    SetActorLocation(Z);

    PrintLocation();
}

void AAssignmentActor::RandomMoveTurn()
{
    for (int i = 0; i < 10; i++)
    {
        float RandomDistance = FMath::RandRange(10.f, 100.f);
        float RandomDegrees = FMath::RandRange(-180.f, 180.f);
        float RandomDeltaZ = FMath::RandRange(-50.f, 50.f);

        Move(RandomDistance);
        Turn(RandomDegrees, RandomDeltaZ);
    }
}
