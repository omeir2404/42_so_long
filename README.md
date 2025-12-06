# so_long

> A minimalist 2D pirate adventure written for the 42 curriculum. Sail across a grid of islands, gather all the coins, then escape through the cave before the seas claim you.

## Highlights
- **Tight tile-based gameplay** – deterministic movement on a 64×64 grid powered by MiniLibX.
- **Robust validation** – custom checks ensure every map is rectangular, surrounded by walls, and has a solvable path that touches every collectible.
- **Custom artwork** – lightweight ASCII XPM textures under `xpm_files/` give the game a cohesive pirate theme that you can tweak or replace.
- **Portable C code** – no external game engines, just the standard 42 support stack (`mlx`, `get_next_line`, and a sprinkle of libft helpers).

## Requirements
| Dependency | Notes |
|------------|-------|
| `make`, `cc` | Any POSIX-compliant toolchain works; project was tested with `cc` on Linux. |
| X11 headers | Install `libx11-dev` and `libxext-dev` (or the equivalents for your distro). |
| MiniLibX | Already vendored under `minilibx-linux/`; built automatically through the project Makefile. |

> 💡 **42 machines** already provide the required toolchain. On Debian/Ubuntu you can run `sudo apt install build-essential libx11-dev libxext-dev zlib1g-dev` if you need to build locally.

## Building & Running
```sh
make            # builds ./so_long using the provided MiniLibX
./so_long maps/map2.ber
```

Useful targets:
- `make clean` – remove intermediate object files.
- `make fclean` – remove objects and the binary.
- `make re` – full rebuild from scratch.

The window size adapts to the map (`width × height` tiles at 64 px each). If the window opens partially off-screen, move it with your window manager or try a smaller map.

## Controls
| Key | Action |
|-----|--------|
| `W` / `↑` | Move up |
| `A` / `←` | Move left |
| `S` / `↓` | Move down |
| `D` / `→` | Move right |
| `Esc` | Close the game |

Every valid move increments the move counter printed in the terminal. Attempting to walk into a wall keeps the player in place and prints `wall` for quick debugging.

## Map Format
Maps live under `maps/` and use the `.ber` extension (plain text). Each line **must** have the same length, and the entire map must be enclosed by walls.

| Character | Meaning |
|-----------|---------|
| `0` | Sea tile / walkable floor |
| `1` | Wall / island tiles (impassable) |
| `C` | Coin (collectible) |
| `E` | Exit cave |
| `P` | Player spawn |

Validation ensures that:
1. The map is rectangular and bounded by `1`s.
2. There is exactly **one** `P`, exactly **one** `E`, and at least **one** `C`.
3. A flood-fill from `P` can reach every collectible and the exit (`path.c`).

To design your own level, copy an existing `.ber` file and edit it with the constraints above. Keep maps reasonably sized to fit on screen; each tile renders at 64 × 64 pixels.

## Project Structure
```
so_long/
├── main.c                # entry point: bootstraps MLX, loads the map, registers hooks
├── srcs/
│   ├── checks*.c         # argument parsing, map validation, flood-fill
│   ├── map.c             # rendering helper
│   ├── move_player*.c    # player movement helpers (in utils.c)
│   └── utils.c           # event hooks, image setup, cleanup
├── GNL/                  # get_next_line implementation for map loading
├── libft_functs/         # minimal libft helpers (ft_strcmp, etc.)
├── minilibx-linux/       # MiniLibX sources for Linux/X11
├── maps/                 # sample .ber maps
├── xpm_files/            # floor/wall/coin/player/exit textures
└── window.h              # shared definitions, structs, constants
```

## Textures & Customization
The renderer maps each character to an image via `make_imgs()` in `srcs/utils.c`. To swap art:
1. Create a 64×64 XPM image (ASCII only) that follows the MiniLibX expectations.
2. Replace the corresponding file in `xpm_files/` (`lastsea.xpm`, `lastisland.xpm`, `lastcoin.xpm`, `Warrior_1.xpm`, `cave.xpm`).
3. Relaunch the game (no rebuild required unless you change code).

> Tip: keep the palette small (under ~256 colors) for faster loading, and stick to square textures so they align cleanly on the grid.

## Troubleshooting
| Symptom | Fix |
|---------|-----|
| `Segmentation fault` on launch | Ensure you pass a map path: `./so_long maps/map.ber`. The program does not display usage information yet. |
| Window fails to open | Check that `mlx_init()` returns non-null; you may be missing X11 libraries if you run on bare WSL. |
| "exit path error" | The map’s exit is unreachable; adjust walls or collectibles so the flood-fill can touch `E`. |
| "collectable path error" | At least one `C` cannot be reached from `P`; rework the level layout. |
| Textures look garbled | Malformed XPM. Validate the header (`"64 64 <colors> 1"`) and ensure every symbol has a palette entry. |

## Credits
- Developed by **Omeir Haroon** "oharoon" as part of the 42 Common Core.
- MiniLibX © 42. See `minilibx-linux/README.md` for its license.
- Custom pirate-themed textures created specifically for this repo; feel free to reskin them for your own practice projects.

Have fun tweaking the seas, crafting devious maps, and expanding the adventure!
