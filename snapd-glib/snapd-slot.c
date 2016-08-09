#include "config.h"

#include <string.h>

#include "snapd-slot.h"

struct _SnapdSlot
{
    GObject parent_instance;

    gchar *name;
    gchar *snap;
    gchar *interface;
    gchar *label;
    // FIXME: connections
};

enum 
{
    PROP_NAME = 1,
    PROP_SNAP,
    PROP_INTERFACE,
    PROP_LABEL,  
    PROP_LAST
};
 
G_DEFINE_TYPE (SnapdSlot, snapd_slot, G_TYPE_OBJECT)

const gchar *
snapd_slot_get_name (SnapdSlot *icon)
{
    g_return_val_if_fail (SNAPD_IS_SLOT (icon), NULL);
    return icon->name;
}


const gchar *
snapd_slot_get_snap (SnapdSlot *icon)
{
    g_return_val_if_fail (SNAPD_IS_SLOT (icon), NULL);
    return icon->snap;
}

const gchar *
snapd_slot_get_interface (SnapdSlot *icon)
{
    g_return_val_if_fail (SNAPD_IS_SLOT (icon), NULL);
    return icon->interface;
}

const gchar *
snapd_slot_get_label (SnapdSlot *icon)
{
    g_return_val_if_fail (SNAPD_IS_SLOT (icon), NULL);
    return icon->label;
}

static void
snapd_slot_set_property (GObject *object, guint prop_id, const GValue *value, GParamSpec *pspec)
{
    SnapdSlot *icon = SNAPD_SLOT (object);

    switch (prop_id) {
    case PROP_NAME:
        g_free (icon->name);
        icon->name = g_strdup (g_value_get_string (value));
        break;
    case PROP_SNAP:
        g_free (icon->snap);
        icon->snap = g_strdup (g_value_get_string (value));
        break;
    case PROP_INTERFACE:
        g_free (icon->interface);
        icon->interface = g_strdup (g_value_get_string (value));
        break;
    case PROP_LABEL:
        g_free (icon->label);
        icon->label = g_strdup (g_value_get_string (value));
        break;
    default:
        G_OBJECT_WARN_INVALID_PROPERTY_ID (object, prop_id, pspec);
        break;
    }
}

static void
snapd_slot_get_property (GObject *object, guint prop_id, GValue *value, GParamSpec *pspec)
{
    SnapdSlot *icon = SNAPD_SLOT (object);

    switch (prop_id) {
    case PROP_NAME:
        g_value_set_string (value, icon->name);
        break;
    case PROP_SNAP:
        g_value_set_string (value, icon->snap);
        break;
    case PROP_INTERFACE:
        g_value_set_string (value, icon->interface);
        break;
    case PROP_LABEL:
        g_value_set_string (value, icon->label);
        break;
    default:
        G_OBJECT_WARN_INVALID_PROPERTY_ID (object, prop_id, pspec);
        break;
    }
}

static void
snapd_slot_finalize (GObject *object)
{
    SnapdSlot *icon = SNAPD_SLOT (object);

    g_clear_pointer (&icon->name, g_free);
    g_clear_pointer (&icon->snap, g_free);
    g_clear_pointer (&icon->interface, g_free);
    g_clear_pointer (&icon->label, g_free);
}

static void
snapd_slot_class_init (SnapdSlotClass *klass)
{
    GObjectClass *gobject_class = G_OBJECT_CLASS (klass);

    gobject_class->set_property = snapd_slot_set_property;
    gobject_class->get_property = snapd_slot_get_property; 
    gobject_class->finalize = snapd_slot_finalize;

    g_object_class_install_property (gobject_class,
                                     PROP_NAME,
                                     g_param_spec_string ("name",
                                                          "name",
                                                          "Slot name",
                                                          NULL,
                                                          G_PARAM_READWRITE | G_PARAM_CONSTRUCT_ONLY));
    g_object_class_install_property (gobject_class,
                                     PROP_SNAP,
                                     g_param_spec_string ("snap",
                                                          "snap",
                                                          "Snap this slot is on",
                                                          NULL,
                                                          G_PARAM_READWRITE | G_PARAM_CONSTRUCT_ONLY));
    g_object_class_install_property (gobject_class,
                                     PROP_INTERFACE,
                                     g_param_spec_string ("interface",
                                                          "interface",
                                                          "Interface this slot consumes",
                                                          NULL,
                                                          G_PARAM_READWRITE | G_PARAM_CONSTRUCT_ONLY));
    g_object_class_install_property (gobject_class,
                                     PROP_LABEL,
                                     g_param_spec_string ("label",
                                                          "label",
                                                          "Short description of this slot",
                                                          NULL,
                                                          G_PARAM_READWRITE | G_PARAM_CONSTRUCT_ONLY));
}

static void
snapd_slot_init (SnapdSlot *icon)
{
}
