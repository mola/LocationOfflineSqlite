# LocationOfflineSqlite

Load {z}/{x}/{y}.jpg from sqlite

Installation from source
------------------------

Qt 5 with the following components:

- Core
- Location
- Location-private
- Positioning-private

For command line builds:
<pre>
$ git clone https://github.com/mola/LocationOfflineSqlite.git
$ cd LocationOfflineSqlite
$ mkdir build
$ cd build
$ qmake ..
$ make
$ sudo make install
</pre>

## Sample code

```
Map {
      activeMapType: map.supportedMapTypes[1]
      zoomLevel: 5
      plugin: Plugin {
         name: 'sqlmaps';
         PluginParameter {
            name: 'source'
            value: '/path/to/map/db.sqlite'
           }
       }
}
```

