import { UserSaveState } from '../types';

const STORAGE_KEY = 'arrow_master_save_v1';

export const DEFAULT_SAVE_STATE: UserSaveState = {
  coins: 100,
  highestUnlockedLevel: 1,
  levelStars: {},
  levelHighScores: {},
  unlockedBows: ['bow_wooden'],
  selectedBow: 'bow_wooden',
  unlockedArrows: ['arrow_classic'],
  selectedArrow: 'arrow_classic',
  achievementsClaimed: {},
  soundEnabled: true,
  musicEnabled: true,
  vibrationEnabled: true,
  highGraphics: true,
  totalHits: 0,
  totalBullseyes: 0,
  totalPerfects: 0,
  maxCombo: 0,
  tutorialCompleted: false,
  lastDailyRewardDate: '',
};

export function loadSaveState(): UserSaveState {
  try {
    const raw = localStorage.getItem(STORAGE_KEY);
    if (!raw) return { ...DEFAULT_SAVE_STATE };
    const parsed = JSON.parse(raw);
    return {
      ...DEFAULT_SAVE_STATE,
      ...parsed,
    };
  } catch {
    return { ...DEFAULT_SAVE_STATE };
  }
}

export function saveGameState(state: UserSaveState): void {
  try {
    localStorage.setItem(STORAGE_KEY, JSON.stringify(state));
  } catch (err) {
    console.error('Failed to save Arrow Master game state to localStorage:', err);
  }
}

export function clearSaveState(): UserSaveState {
  try {
    localStorage.removeItem(STORAGE_KEY);
  } catch {
    // Safe ignore
  }
  return { ...DEFAULT_SAVE_STATE };
}