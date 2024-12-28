#include <gst/gst.h>
#include <stdio.h>
#include "pipeline.h"

#ifdef __APPLE__
#include <TargetConditionals.h>
#endif

void InitializeMediaPipeline (int argc, char *argv[])
{
    printf("Initializing Argus Media Pipeline v0.2.2...\n");
  GstElement *pipeline;
  GstBus *bus;
  GstMessage *msg;

  gst_init (&argc, &argv);

  /* Build the pipeline */
  pipeline =
      gst_parse_launch
      ("playbin uri=https://gstreamer.freedesktop.org/data/media/sintel_trailer-480p.webm",
      NULL);

  /* Start playing */
   printf("Argus Media Pipeline v0.2.2 is Online.\n");
  gst_element_set_state (pipeline, GST_STATE_PLAYING);

  /* Wait until error or EOS */
  bus = gst_element_get_bus (pipeline);
  msg =
      gst_bus_timed_pop_filtered (bus, GST_CLOCK_TIME_NONE,
      GST_MESSAGE_ERROR | GST_MESSAGE_EOS);

  /* See next tutorial for proper error message handling/parsing */
  if (GST_MESSAGE_TYPE (msg) == GST_MESSAGE_ERROR) {
    g_printerr ("An error occurred! Re-run with the GST_DEBUG=*:WARN "
        "environment variable set for more details.\n");
  }

  /* Free resources */
  gst_message_unref (msg);
  gst_object_unref (bus);
  gst_element_set_state (pipeline, GST_STATE_NULL);
  gst_object_unref (pipeline);
}

void main (int argc, char *argv[])
{
    return InitializeMediaPipeline (argc, argv);
}
