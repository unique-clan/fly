#ifndef GAME_SERVER_ENTITIES_FLAG_H
#define GAME_SERVER_ENTITIES_FLAG_H

#include <game/server/entity.h>

class CFlag : public CEntity
{
public:
	static const int m_PhysSize = 14;
	class CCharacter *m_pCarryingCCharacter;
	vec2 m_Vel;
	vec2 m_StandPos;
	
	int m_Team;
	int m_AtStand;
	int m_DropTick;
	int m_GrabTick;
	
	CFlag(CGameWorld *pGameWorld, int Team);

	virtual void Reset();
	virtual void Snap(int SnappingClient);
};

#endif
