#include <game/generated/protocol.h>
#include <game/server/gamecontext.h>
#include "flag.h"
#include "character.h"

CFlag::CFlag(CGameWorld *pGameWorld, int Team)
: CEntity(pGameWorld, NETOBJTYPE_FLAG)
{
	m_Team = Team;
	m_ProximityRadius = m_PhysSize;
	m_pCarryingCCharacter = 0x0;
	m_GrabTick = 0;
	
	Reset();
}

void CFlag::Reset()
{
	m_pCarryingCCharacter = 0x0;
	m_AtStand = 1;
	m_Pos = m_StandPos;
	m_Vel = vec2(0,0);
	m_GrabTick = 0;
}

void CFlag::Snap(int SnappingClient)
{
	CNetObj_Flag *pFlag = (CNetObj_Flag *)Server()->SnapNewItem(NETOBJTYPE_FLAG, m_Team, sizeof(CNetObj_Flag));
	pFlag->m_X = (int)m_Pos.x;
	pFlag->m_Y = (int)m_Pos.y;
	pFlag->m_Team = m_Team;
	pFlag->m_CarriedBy = -1;
	
	if(m_AtStand)
		pFlag->m_CarriedBy = -2;
	else if(m_pCarryingCCharacter && m_pCarryingCCharacter->GetPlayer())
		pFlag->m_CarriedBy = m_pCarryingCCharacter->GetPlayer()->GetCID();
}
