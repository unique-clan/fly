#ifndef GAME_SERVER_GAMEMODES_FLY_H
#define GAME_SERVER_GAMEMODES_FLY_H
#include <game/server/gamecontroller.h>

class CGameControllerFLY : public IGameController
{
public:
	class CFlag *m_apFlags[2];
	
	vec2 *m_pTeleporter;

	CGameControllerFLY(class CGameContext *pGameServer);
	
	void InitTeleporter();
	
	virtual bool CanBeMovedOnBalance(int ClientID);
	virtual void Snap(int SnappingClient);
	virtual void Tick();
	
	virtual bool OnEntity(int Index, vec2 Pos);
	virtual int OnCharacterDeath(class CCharacter *pVictim, class CPlayer *pKiller, int Weapon);
};

#endif
