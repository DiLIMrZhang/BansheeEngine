#include "BsScriptControllerColliderCollision.generated.h"
#include "BsMonoMethod.h"
#include "BsMonoClass.h"
#include "BsMonoUtil.h"
#include "BsScriptGameObjectManager.h"
#include "BsScriptCCollider.generated.h"
#include "Wrappers/BsScriptVector.h"
#include "Wrappers/BsScriptVector.h"

namespace bs
{
	ScriptControllerColliderCollision::ScriptControllerColliderCollision(MonoObject* managedInstance)
		:ScriptObject(managedInstance)
	{ }

	void ScriptControllerColliderCollision::initRuntimeData()
	{ }

	MonoObject*ScriptControllerColliderCollision::box(const __ControllerColliderCollisionInterop& value)
	{
		return MonoUtil::box(metaData.scriptClass->_getInternalClass(), (void*)&value);
	}

	__ControllerColliderCollisionInterop ScriptControllerColliderCollision::unbox(MonoObject* value)
	{
		return *(__ControllerColliderCollisionInterop*)MonoUtil::unbox(value);
	}

	ControllerColliderCollision ScriptControllerColliderCollision::fromInterop(const __ControllerColliderCollisionInterop& value)
	{
		ControllerColliderCollision output;
		GameObjectHandle<CCollider> tmpcollider;
		ScriptCColliderBase* scriptcollider;
		scriptcollider = (ScriptCColliderBase*)ScriptCCollider::toNative(value.collider);
		if(scriptcollider != nullptr)
			tmpcollider = static_object_cast<CCollider>(scriptcollider->getComponent());
		output.collider = tmpcollider;
		output.triangleIndex = value.triangleIndex;
		output.position = value.position;
		output.normal = value.normal;
		output.motionDir = value.motionDir;
		output.motionAmount = value.motionAmount;

		return output;
	}

	__ControllerColliderCollisionInterop ScriptControllerColliderCollision::toInterop(const ControllerColliderCollision& value)
	{
		__ControllerColliderCollisionInterop output;
		ScriptComponentBase* scriptcollider = nullptr;
		if(value.collider)
				scriptcollider = ScriptGameObjectManager::instance().getBuiltinScriptComponent(value.collider);
		MonoObject* tmpcollider;
		if(scriptcollider != nullptr)
			tmpcollider = scriptcollider->getManagedInstance();
		else
			tmpcollider = nullptr;
		output.collider = tmpcollider;
		output.triangleIndex = value.triangleIndex;
		output.position = value.position;
		output.normal = value.normal;
		output.motionDir = value.motionDir;
		output.motionAmount = value.motionAmount;

		return output;
	}

}
