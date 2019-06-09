// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Constraints/ConstraintsGameModeBase.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeConstraintsGameModeBase() {}
// Cross Module References
	CONSTRAINTS_API UClass* Z_Construct_UClass_AConstraintsGameModeBase_NoRegister();
	CONSTRAINTS_API UClass* Z_Construct_UClass_AConstraintsGameModeBase();
	ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
	UPackage* Z_Construct_UPackage__Script_Constraints();
// End Cross Module References
	void AConstraintsGameModeBase::StaticRegisterNativesAConstraintsGameModeBase()
	{
	}
	UClass* Z_Construct_UClass_AConstraintsGameModeBase_NoRegister()
	{
		return AConstraintsGameModeBase::StaticClass();
	}
	struct Z_Construct_UClass_AConstraintsGameModeBase_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AConstraintsGameModeBase_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AGameModeBase,
		(UObject* (*)())Z_Construct_UPackage__Script_Constraints,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AConstraintsGameModeBase_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering Utilities|Transformation" },
		{ "IncludePath", "ConstraintsGameModeBase.h" },
		{ "ModuleRelativePath", "ConstraintsGameModeBase.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AConstraintsGameModeBase_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AConstraintsGameModeBase>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AConstraintsGameModeBase_Statics::ClassParams = {
		&AConstraintsGameModeBase::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x009002A8u,
		METADATA_PARAMS(Z_Construct_UClass_AConstraintsGameModeBase_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_AConstraintsGameModeBase_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AConstraintsGameModeBase()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AConstraintsGameModeBase_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AConstraintsGameModeBase, 2344291414);
	template<> CONSTRAINTS_API UClass* StaticClass<AConstraintsGameModeBase>()
	{
		return AConstraintsGameModeBase::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AConstraintsGameModeBase(Z_Construct_UClass_AConstraintsGameModeBase, &AConstraintsGameModeBase::StaticClass, TEXT("/Script/Constraints"), TEXT("AConstraintsGameModeBase"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AConstraintsGameModeBase);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
