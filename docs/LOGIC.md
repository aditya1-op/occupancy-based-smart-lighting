# Decision logic

```text
Read PIR motion state and LDR analog value
                 |
         Is PIR output HIGH?
                 |
       Is LDR value > 600?
                 |
     Both conditions are TRUE?
           /           \
         Yes            No
          |              |
      LED ON          LED OFF
           \            /
       Print states to Serial Monitor
                 |
          Wait 1 second
                 |
               Repeat
```

The two conditions are combined using Boolean AND. Either no motion or a bright room keeps the LED off.
