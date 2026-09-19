export type GameScreen = 'home' | 'playing' | 'paused';

export type HitZone = 'perfect' | 'bullseye' | 'inner' | 'outer' | 'miss' | 'obstacle';

export interface BowItem {
  id: string;
  name: string;
  description: string;
  price: number;
  unlocked: boolean;
  speedMultiplier: number;
  stabilityBonus: number;
  bodyColor: string;
  accentColor: string;
  stringColor: string;
  glowColor?: string;
  perk: string;
}

export interface ArrowSkinItem {
  id: string;
  name: string;
  description: string;
  price: number;
  unlocked: boolean;
  shaftColor: string;
  fletchColor: string;
  headColor: string;
  particleType: 'classic' | 'silver' | 'gold' | 'fire' | 'ice' | 'lightning';
  glowColor?: string;
}

export interface LevelObstacle {
  x: number;
  y: number;
  width: number;
  height: number;
  speed: number;
  direction: number;
  minX: number;
  maxX: number;
  type: 'log' | 'bird' | 'branch' | 'shield';
}

export interface LevelConfig {
  id: number;
  name: string;
  targetY: number;
  targetRadius: number;
  targetSpeed: number;
  targetPattern: 'horizontal' | 'sine' | 'bounce' | 'pingpong';
  windSpeed: number;
  arrowsCount: number;
  starScores: [number, number, number];
  obstacles: LevelObstacle[];
}

export interface AchievementItem {
  id: string;
  title: string;
  description: string;
  rewardCoins: number;
  unlocked: boolean;
  target: number;
  current: number;
  icon: string;
}

export interface UserSaveState {
  coins: number;
  highestUnlockedLevel: number;
  levelStars: Record<number, number>;
  levelHighScores: Record<number, number>;
  unlockedBows: string[];
  selectedBow: string;
  unlockedArrows: string[];
  selectedArrow: string;
  achievementsClaimed: Record<string, boolean>;
  soundEnabled: boolean;
  musicEnabled: boolean;
  vibrationEnabled: boolean;
  highGraphics: boolean;
  totalHits: number;
  totalBullseyes: number;
  totalPerfects: number;
  maxCombo: number;
  tutorialCompleted: boolean;
  lastDailyRewardDate: string;
}

export interface FlyingArrow {
  x: number;
  y: number;
  vx: number;
  vy: number;
  angle: number;
  skinId: string;
  trail: { x: number; y: number; alpha: number }[];
  active: boolean;
}

export interface Particle {
  x: number;
  y: number;
  vx: number;
  vy: number;
  color: string;
  life: number;
  maxLife: number;
  size: number;
  type: 'spark' | 'smoke' | 'wood' | 'gold' | 'star' | 'fire' | 'ice' | 'lightning' | 'classic' | 'silver';
}

export interface FloatingText {
  id: string;
  text: string;
  subtext?: string;
  x: number;
  y: number;
  color: string;
  scale: number;
  opacity: number;
  vy: number;
}

export interface HitResult {
  zone: HitZone;
  score: number;
  coinsEarned: number;
  isBullseye: boolean;
  isPerfect: boolean;
  distanceFromCenter: number;
}