subdir ('xml')

if get_option ('docs')
  glib_prefix = dependency ('glib-2.0').get_pkgconfig_variable ('prefix')
  glib_docpath = join_paths (glib_prefix, 'share', 'gtk-doc', 'html')
  docpath = join_paths (datadir, 'gtk-doc', 'html')

  private_headers = [ 'mock-snapd.h', 'snapd-json.h' ]

  gnome = import ('gnome')
  gnome.gtkdoc ('snapd-glib',
                main_xml: 'snapd-glib-docs.xml',
                src_dir: [
                  join_paths (meson.source_root (), 'snapd-glib'),
                  join_paths (meson.build_root (), 'snapd-glib')
                ],
                dependencies: snapd_glib_dep,
                scan_args: [
                  '--deprecated-guards="SNAPD_DISABLE_DEPRECATED"',
                  '--rebuild-types',
                ],
                ignore_headers: private_headers,
                fixxref_args: [
                  '--html-dir=@0@'.format (docpath),
                  '--extra-dir=@0@'.format (join_paths (glib_docpath, 'glib')),
                  '--extra-dir=@0@'.format (join_paths (glib_docpath, 'gobject')),
                  '--extra-dir=@0@'.format (join_paths (glib_docpath, 'gio')),
                ],
                install: true)
endif
