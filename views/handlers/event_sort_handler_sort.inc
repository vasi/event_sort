<?php

/**
 * @file
 * Contains event_sort_handler_sort.
 */

/**
 * Custom sort handler for events.
 *
 * Sorts future events before past events, and secondarily sorts events
 * by distance from the current time.
 */
class event_sort_handler_sort extends views_handler_sort {
  function query() {
    $this->ensure_my_table();

    // Generate an alias for the date field.
    $date_alias = $this->table_alias . '.' . $this->real_field;

    // Is this event in the past?
    $this->query->add_orderby(NULL,
      "unix_timestamp() > $date_alias",
      $this->options['order'],
      $this->table_alias . '_in_past'
    );

    // How far in the past/future is this event?
    $this->query->add_orderby(NULL,
      "abs($date_alias - unix_timestamp())",
      $this->options['order'],
      $this->table_alias . '_date_distance'
    );
  }

}
