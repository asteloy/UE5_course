// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Item.h"
#include "Weapon.generated.h"



class USoundBase;
class UBoxComponent;
/**
 * 
 */
UCLASS()
class SLASH_API AWeapon : public AItem
{
	GENERATED_BODY()
public:
	AWeapon();
	void Equip(USceneComponent* InParent, FName InSocketName);

	void AttachMeshToSocket(USceneComponent* InParent, const FName& InSocketName);

protected:
	virtual void BeginPlay() override;

	virtual void OnSphereOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) override;
	virtual void OnSphereEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex) override;
		
	UFUNCTION()
	void OnBoxOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);


private:
	UPROPERTY(EditAnywhere, Category = "Weapons Properties")
	USoundBase* EquipSound;

	UPROPERTY(VisibleAnywhere, Category = "Weapons Properties")
	UBoxComponent* WeaponBox;

public:
	FORCEINLINE UBoxComponent* GetWeaponBox() const { return WeaponBox;  }

	TArray<AActor*> IgnoreActors;

private:
	UPROPERTY(VisibleAnywhere)
	USceneComponent* BoxTraceStart;

	UPROPERTY(VisibleAnywhere)
	USceneComponent* BoxTraceEnd;


};
