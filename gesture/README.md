# Shaka gesture

The shaka gesture is a finger move that allows you to switch between 3 layers. Here in the tutorial, they will be called `Base`, `L2` (for layer 2) and `L3` (for layer 3).

The gesture is called this way because it requires a combination of taps between the thumb and the pinky, which are the same fingers used for the [shaka sign](https://en.wikipedia.org/wiki/Shaka_sign).

The idea was taken from Ben Vallack, who is well-known in the space of ergonomic keyboards. I coined the term "shaka gesture", but he demonstrates his 34-key layout for his Ferris Sweep in [this video](https://youtu.be/8wZ8FRwOzhU?t=445), and he makes use of those locations and fingers to switch to layers. I think it is a convenient mechanism and the combination feels natural to type.

Also, Ben Vallack only switches between layers by locking them, so he does not need to hold a layer key down. He just has to tap them once. It is the same as the "CapsLock" mechanism. However, in pratice, I don't think having layer locks is always the best way to go. First, people that come from regular keyboards are not used to use locks. They mostly use modifiers (`shift`, `ctrl`, `alt`) which should be kept maintained. And even if locks bring less finger fatigue, they are especially useful when multiple keys should be typed. But when you target a single key, they can be cumbersome because you have to lock, type the key and unlock which means three taps.

As an answer, the shaka gesture is a mix of hold and lock.

Let's see that in action. Here is a layout with 34 keys. Regular keys were omitted so that we can focus on layer keys.

On the base layer, there is only one layer key on the thumb that will bring you to the second layer.

<img src="https://raw.githubusercontent.com/lobre/shaka34/main/gesture/shaka_gesture_1.png" width="450">

Note that there are two ways to elevate to this second layer. Either you:

1. hold the thumb key, so that layer 2 is temporarily raised while you hold it,
2. or you tap it once, so that only the next keypress will be taken from layer 2, and then you will be back on the base layer.

Some keyboard firmwares call this mechanism a "one shot".

<img src="https://raw.githubusercontent.com/lobre/shaka34/main/gesture/shaka_gesture_2.png" width="450">

On this second layer, there is another layer key to lead us to layer 3. It is located on the pinky. Here is the shaka sign!

<img src="https://raw.githubusercontent.com/lobre/shaka34/main/gesture/shaka_gesture_3.png" width="450">

Let's say that you came from layer 2 by holding your thumb key (instead of tapping it once to enable the "one shot"). So now, you have two possibilities: Either you:

1. hold your pinky to shift temporarily to layer 3 while you keep maintaining your thumb key (so you have both held),
2. or you tap it once, and it will lock layer 3 and stay locked as long as you keep holding your thumb key.

Most of the time, you will want to do the first option, because holding them both is not super convenient.

And so it will bring you to layer 3 in this position.

<img src="https://raw.githubusercontent.com/lobre/shaka34/main/gesture/shaka_gesture_4.png" width="450">

On layer 3, you also have the same pinky layer key to bring you back to layer 2. It allows you to toggle between layer 2 and layer 3 conveniently.

<img src="https://raw.githubusercontent.com/lobre/shaka34/main/gesture/shaka_gesture_5.png" width="450">

And as soon as you release your thumb key, you will be directly back to the base layer.

<img src="https://raw.githubusercontent.com/lobre/shaka34/main/gesture/shaka_gesture_6.png" width="450">

Great, now you understand how to switch between layers. But if you were carefully reading, you might have the following question:

When switching to layer 2 by tapping the thumb key once (to apply only to the next key press), what will happen if my second key press is the pinky layer key?

And this is where it becomes interesting. When layer 2 is enabled in that manner, the pinky will also transform into a "one shot" key. That means you can in order:
1. tap the thumb key to switch to layer 2 for the next key press,
2. tap the pinky key to switch to layer 3 for the next key press,
3. tap any key from layer 3.

And then you will be directly back to the base layer. That means we can easily type a single key from layer 3 by "rolling" our thumb finger and pinky finger, and by tapping a key. Let's call that the "double one shot" mechanism.

As a sum-up, here are the characteristics of our two layers 2 and 3.

Layer 2 is just above our base layer, and is either activated for one key or for multiple keys when thumb is held. This layer is particularly useful for keys that don't often chain together, but that are usually mixed with letters because we can simply tap the thumb key and input them. So this layer is great for symbols! And if you really need to chain symbols together, you can still hold your thumb key.

Layer 3 is farther from the base layer, but is activated as a lock when the thumb is held and when the pinky is tapped once. So it is good for keys that are less often typed, and for keys that are usually chained together. The use-case for this layer could be arrow keys or numbers. Note that a number could still be rapidly typed after a letter by using the "double one shot" mechanism.

Also, the relationship between layer 2 and layer 3 is interesting. As you can toggle between those two by tapping the pinky, it becomes easy to chain characters that are split apart. Let's say I have symbols on layer 2 and numbers on layer 3. If I need to type `[3]`, I can:

1. hold my thumb key to go to layer 2,
2. type the character `[`,
3. tap the pinky once to lock to layer 3,
4. type `3`,
5. tap the pinky again to go back to layer 2,
6. type the character `]`.


To finish with the shaka gesture, there is one last behavior that it brings. Sometimes, even if layer 3 is meant for less frequent keys, it can be desired to want to stay in this layer for a long time. Let's say you are playing Snake with the arrow keys for instance. Holding the thumb key could become cumbersome. That is why there is one more motion. You can permanently lock layer 3 by double-tapping the pinky layer key. This way, even if you release your thumb key, the keyboard will stay on layer 3. You can then unlock it either by tapping the thumb or pinky key.

Ben Vallack has also taugh me through his videos about something valuable. When you are manipulating layers in an invisible way (no light indicator) and with layer locks, it can happen that you get lost and forget on which layer you are. So there should always be way to go back to the base layer without thinking. And with the shaka gesture, double-tapping the thumb key will just do that!

I hope that you find this system interesting. Feel free to take inspiration for your own keymap!
