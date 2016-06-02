<?php

/**
 * @file
 * Views code for event_sort.
 */

/**
 * Implements hook_views_data_alter().
 */
function event_sort_views_data_alter(&$data) {
  // Add a new sort for events.
  $data['field_data_field_event_date']['event_sort'] = array(
    'group' => t('Content'),
    'title' => t('Event sort'),
    'help' => t('Sort events by past/future, then distance from now'),
    'sort' => array(
      'field' => 'field_event_date_value',
      'handler' => 'event_sort_handler_sort',
    ),
  );
}
