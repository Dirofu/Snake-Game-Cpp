#include "GameMode.h"

namespace SnakeGame
{
    void InitializeGameMode(GameMode& mode)
    {
        mode.mask = 0;
    }

    bool ChangeGameRuleStateByIndex(GameMode& mode, int index)
    {
        if (CheckGameRuleActive(mode.mask, index))
        {
            mode.mask &= ~(1 << (index - 1));
            return false;
        }
        else
        {
            mode.mask |= (1 << (index - 1));
            return true;
        }
    }

    bool CheckGameRuleActive(int mask, int index)
    {
        return mask & (1 << (index - 1));
    }
}