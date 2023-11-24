##

<div>
  <h1 align="center"><font color="green"><code style="color : cyan">SO LONG (115/125)</code></font></h1>
</div>

##

# Percy's Odyssey: A 2D Game Project

## Table of Contents
1. [Welcome to Percy's Odyssey](#welcome-to-percys-odyssey)
2. [The Challenge](#the-challenge)
3. [Game Objectives](#game-objectives)
4. [Graphic Management](#graphic-management)
5. [Map Design](#map-design)
6. [Map Handling](#map-handling)
7. [Feedback and Suggestions](#feedback-and-suggestions)

---

## Welcome to Percy's Odyssey!

Embark on an epic quest inspired by the mythical world of Percy Jackson! This 2D game project is a homage to Rick Riordan's captivating universe, brought to life through the magic of the C language and the graphical prowess of MiniLibX from Codam (https://github.com/codam-coding-college/MLX42).

## The Challenge

The challenge laid before you is to breathe life into a small 2D game, exclusively using the C language. Drawing inspiration from the pages of Percy Jackson's adventures, you'll navigate through the intricacies of lightning bolts as collectibles, portals to Olympus as exits, and menacing minotaurs as adversaries.

## Game Objectives

- **Collect Lightning Bolts:** Embark on a quest to gather shimmering lightning bolts scattered across the digital realm.
- **Navigate with W, A, S, D:** Wield the keys W, A, S, and D to guide Percy through the sacred directions of up, down, left, and right.
- **Record Movements:** Every move etches itself into the chronicles, with the number of movements displayed in the shell.
- **Top-Down Panorama:** Envision the world in a 2D panorama, whether a top-down spectacle or a profile view.
- **Time Unfurls at Your Command:** Time is not a constraint; the game unfolds at the player's command.

## Graphic Management

- **Unfurl the Digital Tapestry:** Let the program unfurl a visual tapestry within a window, weaving the elements of the Percy Jackson universe.
- **Seamless Window Response:** The window, a portal to the digital realm, responds seamlessly to commands, unaffected by transitions.
- **Graceful Exit:** A press of ESC or a click on the window's cross gracefully closes the portal, concluding Percy's digital journey.
- **Embrace MiniLibX Images:** Embrace the chosen images bestowed by MiniLibX.

## Map Design

- **Sacred Map Components:** Forge the map with three sacred components: walls, collectibles (lightning bolts), and free space.
- **Map Language:** The map speaks in simplicity: 0 for open space, 1 for formidable walls, C for coveted lightning bolts, E for the escape route, and P for Percy's genesis.
- **Validation Quest:** A valid map embraces one escape route, at least one lightning bolt, and the spark of Percy's origin. Any duplicates summon an error.
- **Rectangular Canvas:** The map, a rectangular canvas, must be embraced by protective walls. Any deviation summons an error.
- **Path Weaving:** Quest for validity; ensure a path weaves through the fabric of the map.
- **Graceful Exits:** The parser deciphers any map anomaly, exiting with grace and whispering "Error\n" followed by an oracle of wisdom.

## Map Handling

For the sacred task of treating the map, the mystical powers of the `get_next_line` function and the `split` function have been harnessed. These incantations enable the deciphering of the map's language and weaving its components into the digital tapestry.

## Feedback and Suggestions

Feel free to traverse this mythical realm, encounter challenges, and share your insights. Your feedback is welcomed as we embark on the ongoing journey of improving Percy's Odyssey. May your suggestions shape the destiny of this digital epic!
