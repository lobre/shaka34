<img src="https://raw.githubusercontent.com/lobre/shaka34/main/logo.png" width="300">

> Keyboard layout optimized for 34-key keyboards featuring the "shaka gesture".

## Introduction

There are various sizes of ergonomic keyboards. 34-key has become a good reference to have a small enough keyboard while maintaining good ergonomics. However, as not all keys fit on the board, some choices have to be made, and some techniques should be used to activate keys that don't have a reserved physical key. Shaka34 is a layout that is compatible with those 34-key keyboards. There are plenty of other layouts out there, but this one aims to avoid complicated techniques such as [home row mods](https://precondition.github.io/home-row-mods), combos, or tap dance. Those work for a lot of people, but the learning curve can be steep and the mental representation of the keyboard can become tricky.

For shaka34, only those 4 mechanisms are used:

1. **Layer shifts**: key that will switch to another layer while being held (such as `shift`, `ctrl`, `alt` modifiers),
2. **Layer locks**: key that will lock the keyboard to another layer as soon as tapped (such as `capslock`),
3. **OneShots**: key that needs to be tapped once, and that will switch to another layer only for the next keypress.
4. **Double-tap**: key that needs to be tapped twice to lock the keyboard to another layer.

The double-tap is only used once in the layout and for a really specific unfrequent behavior.

I grouped those mechanisms into a system that I called the "shaka gesture". It allows to manipulate 3 layers in an intuitive way, trying to make the switch between them as fluid as possible.

## Shaka gesture

The shaka gesture has its [own documentation page](./gesture/README.md) that I suggest you read before anything else to understand the layout.

## Different kinds of keys

I like to group keys into different groups:

- **Letters**: The alphabet.
- **Numbers**: Well, numbers.
- **Symbols**: All the special characters that are regularly typed for punctuation, for currencies, or in programming languages.
- **Input control keys**: This is also a name that I made up, and it corresponds to keys that will not directly input characters, but instead will control other characters. Technically speaking, there are regular characters but I do like to categorize them differently. The main ones are `space`, `backspace`, `escape`, `enter`, `tab`, ...
- **Function keys**: Keys that are not used to input characters, but that are attributed to functions such as controlling brightness and sound, or keys such as `F1`, `PrintScreen`.
- **Modifiers**: `shift`, `ctrl`, `alt`.

## Selling points of the layout

First, shaka34 is compatible with any operating system layout that has its regular letter keys on the central 3x10 panel. This means that for languages with accentuated characters, they should be doable using this central panel, or using dead keys from special characters.

<img src="https://raw.githubusercontent.com/lobre/shaka34/main/3x10_panel.png" width="600">

It means it is compatible with `qwerty`, but also with `qwerty international`, and many other system layouts. Personally, I am a French typist and I am using [qwerty lafayette 42](https://qwerty-lafayette.org/42). So the below screenshots are with lafayette, but it is close enough to qwerty, so you should not have any problems understanding even if it does not sound familiar.

This repository contains the design of the layout and only [one implementation](./Atreus.ino) for the Atreus keyboard using [kaleidoscope](kaleidoscope.readthedocs.io/).

The layout has `space`, `ctrl` and `shift` on thumbs directly on the base layer. It makes it comfortable even for keyboard shortcuts. Also, it uses one-shot modifiers and one-shot layers. This means you can single-tap modifiers and have them applied to the next character, without having to hold them. Combined with one-shot layers, this allows to apply a modifier from another layer. This is similar to the [callum](https://keymapdb.com/keymaps/callum_oakley/) or the [seniply](https://stevep99.github.io/seniply/) layouts in that regard.

## Layers

Let's go to the interesting part now.

### Base layer

This is the expected base layer with all letters. The star character is a dead key that lafayette uses as a dead key to input accentuated characters.

<img src="https://raw.githubusercontent.com/lobre/shaka34/main/layers/layer_qwerty.png" width="600">

As said above, you can find the main modifiers, and one layer key (which is the thumb layer key of the [shaka gesture](./gesture/README.md)) to bring you to the symbols layer.

Currently, there is no `altgr` key on the layout, but you can configure one on the space key when holding it if needed.

## Symbols layer

All "regular" special characters can be found here. This layer is heavily inspired by the `altgr` layer of [qwerty lafayette 42](https://qwerty-lafayette.org/42#prog)

<img src="https://raw.githubusercontent.com/lobre/shaka34/main/layers/layer_sym.png" width="600">

You can also find there the 2 input control characters `esc` and `tab`.

Remember that the shaka gesture allows you to arrive at this layer from the base layer with a one-shot key (to input a single character from this layer). Also, modifiers can be tapped instead of held to apply to the next character. This means you can type combinations without holding anything such as `ctrl`, then `sym` from the base layer (to raise to this layer) and then `backspace`. This will enter `ctrl+backspace`.

Also note, that this symbols layer is optimized to chain special characters that often arise together (especially for programmers) such as `->`, `=>`, `+=`, `~/`, `#!`.

## Navigation & numbers layer

This layer is raised by the pinky key of the shaka gesture. It allows to type numbers and reach out to navigation keys, but also to type other input control characters such as `enter` and `tab`.

<img src="https://raw.githubusercontent.com/lobre/shaka34/main/layers/layer_nn.png" width="600">

Those characters such as `enter` might seem far from the base layer, hence they might seem complicated to reach. But as explained in the [shaka gesture documentation](./gesture/README.md), the "double one-shot" allows you to rapidly get there.

There is also a key that will do `shift` and `tab` at the same time. It is particularly useful to switch application windows back and forth (with `alt-tab`/`alt-shift-tab`), or to go to the next and previous tabs in the browser (`ctrl-tab`/`ctrl-shift-tab`).

The key `super` (or Windows key) is also there. Many operating system shortcuts use this key. For instance, to switch to the next or previous virtual desktop, you can do `super-left`/`super-right`). Same for tilling window managers such as [i3wm](https://i3wm.org/) which are often configured to switch to desktops with `super-<number>`. This layer allows you to easily do that.

Again, if the `super` key should be applied to a regular key such as `t`, you can from the base layer do:

- hold the thumb key to activate the symbols layer,
- tap the pinky key to lock the navnum layer,
- tap the `super` key to enable it as a one-shot,
- release the thumb key to go back to the base layer,
- type `t`.

It might seem cumbersome while reading those steps, but in practice and when used to it, it is rather fluid.

Numbers are aligned in a numpad layout. The `0` is on the left hand as this position feels better to reach than on a side of the numpad.

You can find again the star key from lafayette here. It is simply because it allows you to type symbols such as `€` or `«`/`»` when combined with numbers. You can change this if you want something else here. You can also replace it with a one-shot layer key that would bring you to another layer to type other special characters of your choice.

To finish, at the bottom left corner of this layout, there is a key to reach and lock the Functions layer.

## Functions layer

This layer will be rarely activated but can be helpful for some ad-hoc specific tasks such as raising the volume or doing a print screen.

<img src="https://raw.githubusercontent.com/lobre/shaka34/main/layers/layer_fn.png" width="600">

It is more complicated to reach this layer, but as it is rarely used, it is still a good tradeoff. As a reminder, to enable it, you can use the "double one-shot" technique. Which means:

- tap the `sym` thumb key,
- tap the `nn` pinky key,
- tap the `fn` key.

This will lock this layer. Once you are done, you can go back to the base layer with the thumb key again.
